#include <iostream>
using namespace std;

long long G[50][50];
int vis[50][50];
long long ans;
int Mx[] = {-1,-1,-2,-2,1,1,2,2};
int My[] = {2,-2,1,-1,2,-2,1,-1};
int dx[]={1,0};
int dy[]={0,1};
int n,m,X,Y;

inline int check(int x,int y)
{
    if(x>=1&&x<=n && y>=1&&y<=m)
    {
        return 1;
    }
    return 0;
}

int main()
{
    cin>>n>>m>>X>>Y;
    n++;m++;X++;Y++;
    //
//    for(int i=0;i<=n;i++)G[i][0]=1;
//    for(int i=0;i<=m;i++)G[0][i]=1;


    G[X][Y]=-1;
    for(int i=0;i<8;i++)
    {
        if(check(X+Mx[i],Y+My[i]))
            G[X+Mx[i]][Y+My[i]] =-1;
    }

    G[1][1]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1&& j ==1)continue;
            if(G[i][j]==-1)G[i][j]=0;
            else
                G[i][j]=G[i-1][j]+G[i][j-1];
        }
    }
//
//    for(int i=0;i<=n;i++)
//    {
//        for(int j=0;j<=m;j++)
//            cout<<G[i][j]<<" ";
//        cout<<endl;
//
//    }
    cout<<G[n][m]<<endl;

    return 0;
}
