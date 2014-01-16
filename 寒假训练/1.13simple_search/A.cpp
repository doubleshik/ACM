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
#include <cctype>
#include <cmath>
#include <list>
#include <map>
using namespace std;


int p,q;
int G[50][50];
int vis[50][50];
int ans[50][50];
int dx[]={-2,-2,-1,-1,1,1,2,2};
int dy[]= {-1,1,-2, 2,-2,2,-1,1};


deque<int> aa;
int flag =false;
int dfs(int x,int y,int num)
{
    if(vis[x][y])
       return G[x][y];
    //cout<<x<<' '<<y<<endl;
    if(num == p*q)
    {
        //cout<<x<<" "<<y<<endl;
        aa.push_back(x*10+y);
        G[x][y]=1;
        flag=true;
        return 1;
    }


    vis[x][y]=1;

    for(int i=0;i<8;i++)
    {
        int ax = x+dx[i],ay = y+dy[i];
        //cout<<"now "<<x<<' '<<y<<' '<<"ax"<<ax<<' '<<ay<<endl;
        if(ax>=0 && ax<p && ay>=0 && ay<q)
        {
            G[x][y] = dfs(ax,ay,num+1);
            if(G[x][y])
            {
                aa.push_back(x*10+y);
             //   cout<<"now"<<x<<' '<<y<<' '<<ax<<"--- "<<ay<<endl;
                break;
            }
        }
    }

    vis[x][y]=0;
   // cout<<G[x][y]<<" --------------"<<endl;
    return G[x][y];

}

int main()
{
    int tst;
    cin>>tst;
    int cse = 0;
    while(tst--)
    {
        cout<<"Scenario #"<<++cse<<":"<<endl;
        cin>>q>>p;

        for(int i=0;i<p;i++)
        {
            for(int j=0;j<q;j++)
            {

                ans[i][j] = dfs(i,j,1);
                if(ans[i][j])
                {
                //    aa.push_back(i*10+j);
                    break;
                }               // cout<<"------"<<endl;
            }
            if(flag)break;
        }

        if(!flag)cout<<"impossible";

        else
        {
            while(!aa.empty())
            {
                int x = aa.back();
                cout<<char('A'+x/10)<<x%10+1;
                aa.pop_back();
            }
        }
        cout<<endl<<endl;
        flag =false;

        memset(vis,0,sizeof(vis));
        memset(G,0,sizeof(G));
    }


    return 0;
}
