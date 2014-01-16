#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

const int maxn = 1000;
int G[maxn][maxn];
  int D[maxn][maxn]={0};
int price[maxn];
int n,m;
int main()
{
    freopen("in.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>price[i];
    }

    for(int i=0;i<m;i++)
    {
        int f,t,r;
        cin>>f>>t>>r;
        if(r==1)G[f][t]=1;
        else{G[f][t]=1;G[t][f]=1;}
    }
    for(int i=0;i<=n;i++)
    {
        G[i][i]=1;
    }
    int maxd=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
        {
          //  cout<<j<<"  "<<i<<"  "<<k<<"    "<<price[k]-price[j]<<endl;
            if(G[j][i] &&G[i][k])
            {
             //   cout<<j<<"  "<<i<<"  "<<k<<"    "<<price[k]-price[j]<<endl;
//                    if(D[j][k] <price[k]-price[j])
//                    {
//                        D[j][k] =price[k]-price[j];
//                        if(D[j][k]>maxd)maxd=D[j][k];
//                    }
                if(price[k]-price[j]>maxd)maxd=price[k]-price[j];
            }
        }

    cout<<maxd<<endl;
    memset(D,0,sizeof(D));
    memset(G,0,sizeof(G));
    return 0;
}
