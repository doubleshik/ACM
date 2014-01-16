#include <iostream>
#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;



const int maxn = 50;


struct node{
    int r,c,l;
};

const int dx[]={0,0,1,-1,0,0};
const int dy[]={0,0,0,0,1,-1};
const int dz[]={1,-1,0,0,0,0};
char  G[maxn][maxn][maxn];
int vis[maxn][maxn][maxn];
int ans[maxn][maxn][maxn];
int L,R,C;
int sx,ex,sy,ey,sz,ez;

inline bool check(int x,int y,int z)
{
    if(x>=0&&x<R && y>=0&&y<C && z>=0&& z<L)return true;
    else
        return false;
}

int bfs()
{

    queue<node> v;
    v.push(node{sx,sy,sz});
    vis[sx][sy][sz]=1;
    ans[sx][sy][sz]=0;
    while(!v.empty())
    {
        node now=v.front();
        int nx=now.r,ny=now.c,nz=now.l;

        int step = ans[nx][ny][nz];
        for(int i=0;i<6;i++)
        {
            int ax = nx+dx[i],ay=ny+dy[i],az=nz+dz[i];
            if(check(ax,ay,az)&&!vis[ax][ay][az] && G[ax][ay][az]=='.'||G[ax][ay][az]=='E')
            {
                // cout<<ax<<" "<<ay<<" "<<az<<endl;
                    ans[ax][ay][az]=step+1;
                    if(ax==ex && ay==ey && az==ez)
                        return 0;
                    v.push(node{ax,ay,az});
                    vis[ax][ay][az]=1;
            }
        }
        v.pop();
    }
    return 0;

}


int main()
{
    freopen("in.txt","r",stdin);

    while(cin>>L>>R>>C &&L !=0)
    {
        getchar();
        for(int z=0;z<L;z++)
        {
            for(int x=0;x<R;x++)
            {
                for(int y=0;y<C;y++)
                {
                    G[x][y][z]=getchar();
                    if(G[x][y][z]=='S'){sx=x;sy=y;sz=z;}
                    if(G[x][y][z]=='E'){ex=x;ey=y;ez=z;}

                }
                getchar();
            }
            getchar();
        }
        bfs();
        if(ans[ex][ey][ez])
            cout<<"Escaped in "<<ans[ex][ey][ez]<<" minute(s)."<<endl;
        else
            cout<<"Trapped!"<<endl;
        memset(ans,0,sizeof(ans));
        memset(vis,0,sizeof(vis));
        memset(G,0,sizeof(G));


    }

    return 0;

}
