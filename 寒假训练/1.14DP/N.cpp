#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;


int G[20][20];
int num[20][20];
pair<int ,int > zero[100];
int dx[]={-1,1,0,0,-1,1};
int dy[]={0,0,-1,1,-1,1};

int N,C;
bool check(int x,int y)
{
    if(x>=0 && x<N &&y>=0 && y<N)
        return true;
    return false;
}


int vis[20][20];
#define pii(x,y) make_pair(x,y)
int bfs(int x,int y)
{
    if(G[x][y]==0 || G[x][y]==-1) return 0;


    queue< pair<int ,int > > q;
    q.push( pii(x,y) );
    vis[x][y]=1;
    int w = G[x][y];
    int t=1;
    int flag =0;
    while(!q.empty())
    {
        int nx = q.front().first, ny = q.front().second;

        for(int k=0;k<6;k++)
        {
            int ax = nx+dx[k],ay=ny+dy[k];

            if(!check(ax,ay)  || vis[ax][ay] )continue;

            if( G[ax][ay] == 0 )flag=1;

            if(G[ax][ay] == w)
            {
                vis[ax][ay]=1;
                q.push( pii(ax,ay) );
                t++;
            }
        }
        q.pop();
    }
    if(flag)return 0;
  //  cout<<w<<"---"<<t<<" --- "<<endl;
    if( w== C)
    {
        return -t;
    }
    return t;

}



int main()
{

    freopen("IN","r",stdin);
    while(cin>>N>>C && N!=0)
    {
        memset(G,-1,sizeof(G));
        int pz=0;

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<=i;j++)
            {
                cin>>G[i][j];

            }
        }

        int ans = -10000;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<=i;j++)
            {

                int d=0;
                if(G[i][j]==0)
                {
                    G[i][j] =C;
                    memset(vis,0,sizeof(vis));
                    for(int p=0;p<N;p++)
                    for(int q=0;q<=i;q++)
                        if(!vis[p][q])
                        {
                            d+=bfs(p,q);
//                            cout<<p<<" "<<q<<endl;
//                            cout<<bfs(p,q)<<" dd"<<endl;
                        }

                    G[i][j] = 0;
                    ans = max(ans, d);
                }

            }
        }
        cout<<ans<<endl;

    }


    return 0;
}
