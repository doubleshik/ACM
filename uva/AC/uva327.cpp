#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
char temp[200];
char str[200];
int ps=0;
int single[200];
int vis[200];
int main()
{
    //freopen("in.txt","r",stdin);

    while(gets(temp))
    {
        ps=0;
        for(int i=0;i<strlen(temp);i++)
        {
            if(temp[i]!=' ')str[ps++]=temp[i];
        }

        cout<<"Expression: "<<temp<<endl;
        int value = 0;
        for(int i=0;i<strlen(str); )
        {
            if(!i && isalpha(str[i])) {value += str[i]-'a'+1;single[str[i]-'a'] = str[i]-'a'+1;vis[str[i]-'a']=1; i++;}
                if(str[i]==str[i+1]&& str[i+1]=='+')
                {
                    if( i && isalpha(str[i-1]))
                    {
                        single[str[i-1]-'a'] ++;
                        i+=2;
                    }
                    else if( isalpha(str[i+2]))
                    {
                        value+= str[i+2]-'a'+2;
                        single[str[i+2]-'a'] = str[i+2]-'a'+2;
                        vis[str[i+2]-'a'] =1;
                         i+=3;
                    }

                }
                if(str[i]==str[i+1]&& str[i+1]=='-')
                {
                    if( i && isalpha(str[i-1]))
                    {
                        single[str[i-1]-'a'] --;
                        i+=2;
                    }
                    else if( isalpha(str[i+2]))
                    {
                        value+= str[i+2]-'a';
                        single[str[i+2]-'a'] = str[i+2]-'a';
                        vis[str[i+2]-'a'] =1;

                        i+=3;
                    }
                }

                if(str[i]=='+')
                {
                    int tt=i;
                    while(!isalpha(str[tt]))tt++;

                    if(tt-1==i)
                    {
                        value+=str[tt]-'a'+1;
                        single[str[tt]-'a'] = str[tt]-'a'+1;
                        vis[str[tt]-'a'] =1;
                        i=tt+1;

                    }
                    else
                    {
                        if(str[tt-1]=='-')
                        {
                            value += str[tt]-'a';
                            single[str[tt]-'a'] = str[tt]-'a' ;
                            vis[str[tt]-'a'] =1;
                            i=tt+1;
                        }
                    }
                }
                else if(str[i]=='-')
                {
                     int tt=i;
                    while(!isalpha(str[tt]))tt++;
                    if(tt-1==i)
                    {
                        value-=str[tt]-'a'+1;
                        single[str[tt]-'a'] = str[tt]-'a'+1;
                        vis[str[tt]-'a'] =1;
                        i=tt+1;
                    }
                    else
                    {
                        if(str[tt-1]=='+')
                        {
                            value -= str[tt]-'a'+2;
                            single[str[tt]-'a'] = str[tt]-'a'+2 ;
                           vis[str[tt]-'a'] =1;
                            i=tt+1;
                        }
                    }


                }




        }



        cout<<"    value = "<<value<<endl;
        for(int i=0;i<26;i++)
        {
            if(vis[i])
            {
                cout<<"    "<<char('a'+i)<<" = "<<single[i]<<endl;
            }
        }
        value=0;
        memset(temp,0,sizeof(temp));
        memset(str,0,sizeof(str));
        memset(single,0,sizeof(single));
        memset(vis,0,sizeof(vis));
    }
    return 0;
}
