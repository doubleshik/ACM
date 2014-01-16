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


map<int ,vector<int> > v;
int main()
{
    int num,q;
    while(scanf("%d%d",&num,&q)!=EOF)
    {
        for(int i=0;i<num;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            v[tmp].push_back(i+1);
        }

        for(int i=0;i<q;i++)
        {
            int k,n;
            scanf("%d%d",&k,&n);

            if(v.count(n))
            {
                if(v[n].size()<k)
                {
                    cout<<'0'<<endl;

                }
                else
                {
                    cout<<v[n][k-1]<<endl;
                }
            }
            else
            {
                cout<<'0'<<endl;
            }
        }

    }




    return 0;
}
