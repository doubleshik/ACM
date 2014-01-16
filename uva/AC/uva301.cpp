#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;

int n,city,order;

struct pas
{
    int start,dest;
    int num;
    bool operator < (const pas& x) const
    {
        return start<x.start;
    }
}G[100];
int pG;
int mark[100];
int earns;
void dfs(int u,int money)
{
    pas& now = G[u];
    for(int i=now.start;i<now.dest;i++)
    {
        mark[i]+=now.num;
        if(mark[i]>n)
        {
            for(;i>=now.start;i--)
            {
                mark[i]-=now.num;
            }
            return ;
        }
    }
    money += now.num*(now.dest-now.start);

    if(money>earns)earns=money;

    for(int i=u+1;i<pG;i++)
    {
        dfs(i,money);
    }


     for(int i=now.start;i<now.dest;i++)
     {
         mark[i]-=now.num;
     }
    return ;
}


int main()
{

    while(cin>>n>>city>>order &&( n|| city||order))
    {

        for(int i=0;i<order;i++)
        {
            int s,e,p;
            cin>>s>>e>>p;
            G[pG++]=pas({s,e,p});
        }

        sort(G,G+pG);
        for(int i=0;i<order;i++)
        {
            dfs(i,0);
        }
        cout<<earns<<endl;
        pG=0;
        earns=0;
        memset(G,0,sizeof(G));
        memset(mark,0,sizeof(mark));
    }

    return 0;
}
