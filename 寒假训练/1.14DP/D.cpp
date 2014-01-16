//Tue Jan 14 22:08:50 2014
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
#define INF 99999999
#define MAX 100+10
int G[MAX][MAX];

int n;
int floyd()
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(k!=i && k!=j)
                    G[i][j] = min ( G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    return 0;

}

int main()
{
    freopen("IN","r",stdin);

    while(cin>>n && n!=0)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {

                G[i][j] = INF;
            }
            G[i][i]=0;
        }

        for(int i=0;i<n;i++)
        {
            int t;
            cin>>t;

            for(int j=0;j<t;j++)
            {
                int a,b;
                cin>>a>>b;
                G[i][a-1] = b;
            }
        }

        floyd();


        int MM=0,MIN=INF;
        int rec=0;
        int flag = false;
        for(int i=0;i<n;i++)
        {
            MM=0;
            for(int j=0;j<n;j++)
            {
                MM = max(MM, G[i][j]);
            }

            if( MM != INF)
            {
                flag = true;
            }
            if(MIN>MM)
            {
                rec=i;
                MIN = MM;
            }
        }
        if(!flag)
            cout<<"disjoint"<<endl;
        else
            cout<<rec+1<<" "<<MIN<<endl;
    }

    return 0;
}
