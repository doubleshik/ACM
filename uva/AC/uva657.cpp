#include <iostream>
#include <memory.h>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int G[100][100];
int vis[100][100];
int row,line,cse=0;
typedef pair <int,int> pii;

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};


void print()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<line;j++)
            cout<<vis[i][j]<<" ";

        cout<<endl;
    }
    cout<<endl<<endl;
}


inline bool check(int x,int y)
{
    if(x>=0 && x<row && y>=0 &&y<line)return true;
    else
        return false;
}
int bfs(int x,int y )
{
    queue<pii> v;
    v.push(make_pair(x,y));
    while(!v.empty())
    {
        pii now = v.front();
        int nx=now.first,ny=now.second;

        for(int i=0;i<4;i++)
        {
            int ax = nx+dx[i],ay=ny+dy[i];
            if(check(ax,ay)&&!vis[ax][ay] && G[ax][ay]=='X')
            {
                v.push(make_pair(ax,ay));
                vis[ax][ay]=1;
            }
//            else if(check(ax,ay)&&!vis[ax][ay] && G[ax][ay]=='*')
//            {
//                vis[ax][ay]=1;
//            }
        }
        vis[nx][ny]=1;
        v.pop();
    }
}

int ppo[100];
int pa=0;
int dfs_back(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int ax = x + dx[i] , ay = y+dy[i];
        if(check(ax,ay)&& !vis[ax][ay] && G[ax][ay]=='*')
        {
            dfs_back(ax,ay);
        }
        else if(check(ax,ay)&& !vis[ax][ay] && G[ax][ay]=='X')
        {
            ppo[pa]++;
           // print();
            bfs(ax,ay);
            dfs_back(ax,ay);
        }
    }

}

int main()
{

    freopen("in.txt","r",stdin);
    while(cin>>line>>row &&row!=0 && line!=0)
    {
        cout<<"Throw "<<++cse<<endl;
        getchar();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<line;j++)
                G[i][j]=getchar();
            getchar();
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<line;j++)
            {
                if(!vis[i][j] && G[i][j]=='*')
                {
                    dfs_back(i,j);
                    pa++;
                    //print();
                }
                else if(G[i][j]=='.')
                    {vis[i][j]=1;}
            }

        }
        sort(ppo,ppo+pa);
        for(int i=0;i<pa-1;i++)
        {
            if(ppo[i])
            cout<<ppo[i]<<" ";
        }
        if(ppo[pa-1])
        cout<<ppo[pa-1];
        cout<<endl<<endl;

        pa=0;
        memset(vis,0,sizeof(vis));
        memset(G,0,sizeof(G));
        memset(ppo,0,sizeof(ppo));
    }

    return 0;
}
