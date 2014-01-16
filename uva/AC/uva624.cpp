//Wed Jan  1 17:26:55 2014
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
using namespace std;

int tape,tn;
int tracks[50];
int ans[2000];
int rec[2000][2000];
void printlol(int n,int c)
{
    if(n==0) return ;
    if(n==1 && rec[n][c]>0){printf("%d ",rec[n][c]);return;}

    if(rec[n][c]>0)
    {
        printlol(n-1,c-tracks[n]);
        printf("%d ",tracks[n]);
    }
    else
        printlol(n-1,c);
}
int main()
{
    while(cin>>tape>>tn)
    {
        for(int i=1;i<=tn;i++)
        {
            cin>>tracks[i];
        }

        for(int i=1;i<=tn;i++)
        {
            for(int v=tape;v>=0;v--)
            {
                rec[i][v]=0;
                if(v>=tracks[i])                //注意不要少等号
                {
                    //ans[v] = max(ans[v],ans[v-tracks[i]]+tracks[i]);
                    if(ans[v]<ans[v-tracks[i]]+tracks[i])
                    {
                        ans[v] = ans[v-tracks[i]]+tracks[i];
                        rec[i][v] = tracks[i];
                    }
                }
            }
        }
        printlol( tn,tape );

        cout<<"sum:"<<ans[tape]<<endl;
        for(int i=0;i<=tape;i++)
        {
            ans[i]=0;
        }
        memset(rec,0,sizeof(rec));
    }

    return 0;
}
