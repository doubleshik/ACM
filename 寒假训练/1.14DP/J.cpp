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


char G[51][51];
long long dp[51][51];

long long gcd(long long a,long long b)
{
    if(b==0)return a;
    else
        return gcd(b,a%b);
}

int main()
{
  //  freopen("IN","r",stdin);
    int n,m;
    cin>>n>>m;
    //cin.ignore();
    memset(G,'*',sizeof(G));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                cin>>G[i][j];
            }
        }
     //   cout<<endl;

    dp[0][0] = (long long)1<<n;
//    dp[n][m] = (long long)1<<n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(G[i][j]=='*')
            {
                dp[i+1][j] += dp[i][j]/2;
                dp[i+1][j+1] += dp[i][j]/2;
            }
            else
            {
                dp[i+2][j+1]  += dp[i][j];
            }
        }
    }
    long long d = gcd(dp[n][m],(long long)1<<n);
    cout<<dp[n][m]/d<<"/"<<((long long)1<<n)/d<<endl;

    return 0;
}
