#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int R,C;
int G[101][101];
int dp[101][101];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int dfs(int x,int y)
{
    int &d = dp[x][y];
    if(d) return d;


    d=1;
    for(int i=0;i<4;i++)
    {
        int ax=x+dx[i],ay=y+dy[i];
        if(ax>=0&&ax<R && ay>=0&&ay<C)
        {
            if(G[x][y]>G[ax][ay])
                d = max(d, dfs(ax,ay)+1);
        }
    }
    return d;

}


int main()
{
 //   freopen("IN","r",stdin);
    cin>>R>>C;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>G[i][j];
        }
    }
    int tt=0;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            tt = max(tt,dfs(i,j));
        }

    }

    cout<<tt<<endl;


    return 0;
}
