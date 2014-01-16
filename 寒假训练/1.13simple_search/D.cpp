//Mon Jan 13 13:04:07 2014
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
//#include <memory.h>
#include <cctype>
#include <cmath>
#include <list>
#include <map>
using namespace std;
int n,k;

char G[10][10];
int vis[10][10];
int kk[10];
int total=0;
int dfs(int x,int y,int num)
{
    if(num == k)
    {
        total++;
        return 0;
    }

    for(int i=x+1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            bool flag = true;
            if( G[i][j]=='#')
            {
                for(int m=0;m<=x;m++)
                {
                    if(j==kk[m])
                    {
                        flag =false;
                        break;
                    }
                }
                if(flag)
                {
                    kk[i] =j;
                    dfs(i,j,num+1);
                    kk[i]=-1;
                }
            }

        }
    }

    return 0;
}


int main()
{
    freopen("IN","r",stdin);
    while(cin>>n>>k && n!=-1)
    {
        cin.ignore();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>G[i][j];
            cin.ignore();
        }
//
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                cout<<G[i][j];
//            }
//            cout<<endl;
//        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(G[i][j]=='#')
                {
                    kk[i]=j;
                    dfs(i,j,1);
                    kk[i]=-1;
                }
            }
        }


        cout<<total<<endl;

        total=0;
        memset(vis,0,sizeof(vis));
        memset(kk,0,sizeof(kk));


    }



    return 0;
}
