#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

int n,m;

int G[50][50];
int vis[50];
int maxlen;
void dfs(int u,int len)
{
    if(len>maxlen)maxlen=len;
    for(int i=0;i<n;i++)
    {
        if(G[u][i])
        {
            G[u][i]=0;G[i][u]=0;
            dfs(i,len+1);
            G[u][i]=1;G[i][u]=1;
        }
    }


}
int main()
{

    while(cin>>n>>m && n!=0 && m!=0)
    {
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            G[x][y]=1;G[y][x]=1;
        }
        for(int i=0;i<n;i++)
            dfs(i,0);

        cout<<maxlen<<endl;
        maxlen=0;
        memset(G,0,sizeof(G));
        memset(G,0,sizeof(G));

    }


    return 0;
}
