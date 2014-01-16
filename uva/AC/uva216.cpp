#include <iostream>
#include <cmath>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;

struct com{
    int x,y;
}Com[20];

double D[20][20]={0};
int vis[20];
inline double dis(int x1,int y1,int x2,int y2){ return sqrt(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));}
int rec[20];
int fin[20];
#define INF 10000000
int n;
double total=10000000;
int dfs(int u,double v,int p)
{
    if(p==n)
    {
        if(v<total)
        {
            memcpy(fin,rec,sizeof(rec));
            total=v;
        }
    }
    vis[u]=1;

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
//            for(int j=0;j<n;j++)cout<<vis[j]<<" ";
//            cout<<"  V"<<v<<endl;
            rec[p]=i;
            dfs(i,v+D[u][i],p+1);
        }
    }
    vis[u]=0;
    return 0;
}

int main()
{
    freopen("in.txt","r",stdin);

    int tst=0;
    while(cin>>n &&n!=0)
    {
        for(int i=0;i<n;i++)
        {
            cin>>Com[i].x>>Com[i].y;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                D[i][j]=dis(Com[i].x,Com[i].y,Com[j].x,Com[j].y);
            }
        }
        for(int i=0;i<n;i++)
        {
            rec[i]=i;
        }

        double minn = 2147483645;
        do
        {
            double  ans =0;
            for(int i=0;i<n-1;i++)
            {
                ans+= D[rec[i]][rec[i+1]]+16;
            }
            if(ans<minn)
            {
                minn=ans;
                memcpy(fin,rec,sizeof(rec));
            }
        }while(next_permutation(rec,rec+n));


        double finans=0;
        printf("**********************************************************\n");
        printf("Network #%d\n",++tst);
        for(int i=0;i<n-1;i++)
        {
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",Com[fin[i]].x,Com[fin[i]].y,
                   Com[fin[i+1]].x,Com[fin[i+1]].y,D[fin[i]][fin[i+1]]+16);
            finans += D[fin[i]][fin[i+1]]+16;
        }
        printf("Number of feet of cable required is %.2lf.\n",finans);

        memset(rec,0,sizeof(rec));
        memset(vis,0,sizeof(vis));
        memset(D,0,sizeof(D));
    }

    return 0;
}
