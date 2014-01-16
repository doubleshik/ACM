#include <iostream>
#include <queue>
#include <set>
#include <iterator>
#include <list>
#include <memory.h>
#include <cstdio>
using namespace std;

struct state{
    int color;
    int dir;
    int x,y;
};

// dir  N :0shang , S,1 xia, W :2 zuo E : 3 you
//color : GREEN 0, BLACK 1 RED2 BLUE 3 WHITE4
char G[100][100];
int ans[100][100][5][4];
int M,N;
int dx[] = {1,-1,0,0};
int dy[]  = {0,0,1,-1};

int cse=0;
void bfs()
{
    memset(ans,-1,sizeof(ans));
    int sx,sy,fx,fy;
    for(int ki=0;ki<M;ki++)
    {
        for(int kj=0;kj<N;kj++)
        {
            if(G[ki][kj]=='S')
            {ans[ki][kj][0][0]=0;sx=ki;sy=kj;}
            if(G[ki][kj]=='T')
            {fx=ki;fy=kj;}
        }
    }

    queue<state> v;
    state tmp;
    tmp.x =sx; tmp.y= sy;tmp.color=0;tmp.dir=0;
    v.push(tmp);


    int flag = false;

    while(!v.empty())
    {
        state& n = v.front();
        //if(n.x==9 && n.y==9)cout<<"-----------------"<<endl;

        int &pp = ans[n.x][n.y][n.color][n.dir];
        int ax,ay;

            int &gg = ans[n.x][n.y][n.color][((n.dir+1)%4+4)%4];
            if(gg==-1 || pp+1<gg)
            {
              gg= pp+1;
              tmp.x = n.x;tmp.y=n.y;
              tmp.dir=((n.dir+1)%4+4)%4;
              tmp.color=n.color;
              v.push(tmp);
            }
            int &mm = ans[n.x][n.y][n.color][((n.dir-1)%4+4)%4];
            if( mm==-1 || pp+1<mm  )
            {
              mm= pp+1;
              tmp.x = n.x;tmp.y=n.y;
              tmp.dir=((n.dir-1)%4+4)%4;
              tmp.color=n.color;
              v.push(tmp);
            }


            if(n.dir == 0) {ax=n.x-1;ay=n.y;}
            if(n.dir==1){ax = n.x+1;ay=n.y;}
            if(n.dir==2){ax=n.x;ay=n.y-1;}
            if(n.dir==3){ax=n.x;ay=n.y+1;};

            if(ax>=0&&ax<M && ay>=0 &&ay<N)
            {
                int &xx = ans[ax][ay][((n.color+1)%5+5)%5][n.dir];
                if(G[ax][ay]!='#' && (xx==-1 || pp+1<xx))
                {
                    xx = pp+1;
                    tmp.x = ax;tmp.y=ay;tmp.dir=n.dir;tmp.color=((n.color+1)%5+5)%5;
                    v.push(tmp);
                }
            }
            if(n.x==fx && n.y==fy)
                cout<<n.x<<' '<<n.y<<' '<<n.color<<' '<<n.dir<<' '<<ans[n.x][n.y][n.color][n.dir]<<endl;
        v.pop();
    }

    int MIN = 0x7ffffff;
    for(int i=0;i<4;i++)
    {
        cout<<ans[fx][fy][0][i]<<endl;
        MIN= min(MIN,ans[fx][fy][0][i]);
    }

    if(MIN!=-1)
    {cout<<"Case #"<<++cse<<endl;
        cout<<"minimum time = "<<MIN<<" sec"<<endl;
    }
    else
     cout<<"Case #"<<++cse<<endl<<"destination not reachable"<<endl;
}
int main()
{
    freopen("IN","r",stdin);
    while(cin>>M>>N && M+N!=0)
    {
        if(cse)cout<<endl;
        cin.ignore();
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>G[i][j];
            }
            cin.ignore();
        }
        bfs();
        //v.clear();
    }

    return 0;
}
