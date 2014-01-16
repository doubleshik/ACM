#include <iostream>
#include <cstdio>

using namespace std;


int N;
int G[30][30];
int index[30];
int MAX;
int dfs(int x ,int now)
{
    if( x == N)
    {
        MAX = max(MAX,now);
        return 0;
    }

    dfs(x+1,now);

    int tmp=0;
    for(int i=0;i<N;i++)
    {
        if(index[i])
        {
            tmp-=G[x][i];
        }
        else
        {
            tmp+= G[x][i];
        }
    }
    if(tmp>0)
    {
        index[x] = 1;
        dfs(x+1,now+tmp);
        index[x] = 0;
    }
    return 0;
}

int main()
{
   // freopen("IN","r",stdin);
    scanf("%d",&N);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            scanf("%d",&G[i][j]);
    }

    dfs(0,0);
    cout<<MAX<<endl;
    return 0;
}
