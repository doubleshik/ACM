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
#include <memory.h>
#include <cctype>
#include <cmath>
#include <list>
#include <map>
using namespace std;


#define REP(i,N) for(int i=0;i<N;i++)
int L,R,C ;
int sx,sy,sz,fx,fy,fz;
char G[40][40][40];
int vis[40][40][40];
struct P
{
    int x,y,z;
    int time;
    P(int a,int b,int c,int d): x(a),y(b),z(c),time(d){}
};
int dx[]= {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};
bool jud(int x,int y,int z)
{
    if(x>=0&& x<L &&y>=0&&y<R&&z>=0&&z<C)
        return true;

    return false;

}
int flag= false;
void bfs()
{

    queue<P> v;
    v.push(P(sx,sy,sz,0));

    while(!v.empty())
    {
        P tmp  = v.front();

        if(tmp.x==fx&&tmp.y==fy&&tmp.z==fz)
        {
            cout<<"Escaped in "<<tmp.time<<" minute(s)."<<endl;
            flag =true;
            return;
        }
        REP(i,6)
        {
                    int ax =tmp.x+dx[i],ay=tmp.y+dy[i],az=tmp.z+dz[i];
                    if(jud(ax,ay,az) && !vis[ax][ay][az] && G[ax][ay][az]!='#')
                    {
                        vis[ax][ay][az]=1;
                        v.push(P(ax,ay,az,tmp.time+1));
                    }

        }

        v.pop();


    }


}


int main()
{
    freopen("IN","r",stdin);
    while(cin>>L>>R>>C && L!=0)
    {
        cin.ignore();
        REP(i,L)
        {
            REP(j,R)
            {
                REP(k,C)
                {
                    cin>>G[i][j][k];
                    if(G[i][j][k]=='S')
                    {
                        sx=i;sy=j;sz=k;
                    }
                    if(G[i][j][k]=='E')
                    {
                        fx=i;fy=j;fz=k;
                    }
                }
                cin.ignore();
            }
            cin.ignore();
        }

        bfs();

        if(!flag)
        {
            cout<<"Trapped!"<<endl;

        }


         flag = false;

        memset(vis,0,sizeof(vis));
//        REP(i,L)
//        REP(j,R)
//        {
//            REP(k,C)
//            {
//                cout<<G[i][j][k];
//            }
//            cout<<endl;
//        }

    }



    return 0;
}
