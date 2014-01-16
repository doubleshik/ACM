#include <cstdio>
#include <iostream>
#include <algorithm>
#include <malloc.h>
#include <memory.h>
using namespace std;

const int maxn =1000;
struct bign
{
    int len,s[maxn];
    bign(){memset(s,0,sizeof(s));len=1;}

    bign(int num){*this = num;}
    bign(const char*num){*this=num;}


    bign operator = (int num)
    {
        char s[maxn];
        sprintf(s,"%d",num);
        *this = s;
        return *this;
    }


    bign operator = (const char* num)
    {
        len=strlen(num);
        for(int i=0;i<len;i++) s[i]=num[len-i-1]-'0';
        return *this;
    }

    bign operator + (const bign& b) const
    {
        bign c;
        c.len=0;

        for(int i=0,g=0;g||i<max(len,b.len);i++)
        {
            int x=g;
            if(i<len) x+=s[i];
            if(i<b.len)x+=b.s[i];
            c.s[c.len++] = x%10;
            g=x/10;
        }
        return c;
    }


    string str() const
    {
        string res="";
        for(int i=0;i<len;i++)res=(char)(s[i]+'0')+res;
        if(res=="")res="0";
        return res;
    }

    bool operator <(const bign& b)const
    {
        if(len!=b.len)return len<b.len;
        for(int i=len-1;i>=0;i--)
            if(s[i]!=b.s[i])return s[i]<b.s[i];
        return false;

    }
    bool operator != (const bign& b)const {return b<*this ||*this<b;}


};


istream& operator >>(istream &in,bign& x)
{
    string s;
    in>>s;
    x=s.c_str();
    return in;

}
ostream& operator << (ostream &out,const bign& x)
{
    out<<x.str();
    return out;
}


int main()
{
    bign a,b;
    bign ans=0;
    cin>>a;
    while(a!=0)
    {
        ans=ans+a;
        cin>>a;

    }
    cout<<ans<<endl;


}
