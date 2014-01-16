//Tue Jan 14 22:08:50 2014
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

int N;
int T[105][105];

int dp[105][105];

int dfs(int x,int y)
{
        int &d = dp[x][y];

        if(d)return d;
        if(x>N)return 0;


        d = max( dfs(x+1,y), dfs(x+1,y+1) )+T[x][y];
     //   cout<<d<<endl;
        return d;
}

int main()
{
   // freopen("IN","r",stdin);
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>T[i][j];

        }
    }


    dfs(1,1);
    cout<<dp[1][1]<<endl;
    return 0;
}
