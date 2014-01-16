//Sat Jan 11 13:25:58 2014
//Author:Minshik
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <memory.h>
#include <cctype>
#include <cmath>
#include <list>
using namespace std;

int Mr[26];
int Ml[26];
int main()
{

    freopen("IN","r",stdin);
    int N;
    cin>>N;
    cin.ignore();
    for(int i=0;i<N;i++)
    {
        char c;
        cin>>c;
        cin>>Mr[c-'A']>>Ml[c-'A'];

     //   cout<<c<<' '<<Mr[c-'A']<<' '<<Ml[c-'A'];
    }

    string exp;
    stack <int> v;
    while(cin>>exp)
    {
        int k=0;bool flag =true;
       for(int i=0;i<exp.length();i++)
       {

            if(v.empty())
            {
                if(isalpha(exp[i]))
                {
                    v.push( Mr[exp[i]-'A']);
                    v.push( Ml[exp[i]-'A']);

                }
            }
            if( exp[i]==')')
            {
                int a = v.top();v.pop();
                int b = v.top();v.pop();

                int c = v.top();v.pop();
                if(b==c)
                {
                    k+= v.top()*c*a;
                    v.push(a);
                }
                else
                    {
                        flag =false;
                        break;
                    }
            }
            else if( isalpha(exp[i]))
            {
                    v.push( Mr[exp[i]-'A']);
                    v.push( Ml[exp[i]-'A']);
            }

        }

        if(!flag)
        {
            cout<<"error"<<endl;
        }
        else
        {
            cout<<k<<endl;
        }

    }



    return 0;
}
