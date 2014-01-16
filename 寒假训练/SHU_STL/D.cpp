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
using namespace std;
#define ll long long


struct cmp{

    bool operator() (const ll a , const ll b)
    {
        return a>b;
    }
};

priority_queue<ll,vector<int> ,cmp > q;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF )

    {
        if(n==0)break;

        for(int i=0;i<n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            q.push(tmp);
        }
        ll sum=0,tmp=0;
//        sort(q,q+q.size());

        while(!q.empty())
        {
            tmp = q.top();

            q.pop();

            if(!q.empty())
            {
                sum+=tmp+q.top();

                int d=q.top();
                q.pop();
                q.push(tmp+d);
            }
        }
        printf("%ld\n",sum);

    }


    return 0;
}
