//Sat Jan 11 23:30:37 2014
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
#include <map>
using namespace std;
#define ll long long

stack<ll> e;
stack<ll > v;
int main()
{
    //freopen("IN","r",stdin);
    int n;
    cin>>n;
    cin.ignore();
    while(n--)
    {
        ll num;char c;
        scanf("%lld",&num);
        e.push(num);
        v.push(num);
        while(scanf("%c",&c)!=EOF)
        {
            if(c=='\n')break;

            scanf("%lld",&num);

                if(c=='+')
                {
                    ll c = e.top()+num;
                    e.pop();e.push(c);

                    v.push(num);
                }
                else if(c=='*')
                {
                    ll c=v.top()*num;
                    v.pop();v.push(c);

                    e.push(num);
                }

                //cout<<e.top()<<endl;

        }
        ll MAX=1,MIN=0;
        while(!e.empty())
        {
            MAX*=e.top();e.pop();
        }
        while(!v.empty())
        {
            MIN+=v.top();v.pop();
        }

        printf("The maximum and minimum are %lld and %lld.\n",MAX,MIN);
      //  cout<<"The maximum and minimum are "<<MAX<<" and "<<MIN<<"."<<endl ;

    }


    return 0;
}
