//Sun Jan 12 20:14:41 2014
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
long long n,k;
int dp[300][10];


int dfs(int m,int k,int deep)
{

    if(m-deep<=0  || k>m)return 0;

    int &d = dp[m][k];
    if(d)return d;
    if(k==1)return d=1;


    for(int l = deep;l<m;l++)
    {
        d+= dfs(m-l,k-1,l);
    }
    return d;

}

int main()
{

    cin>>n>>k;


    for(int l=1;l<n;l++)
    {
        dp[n][k] += dfs(n-l,k-1,l);
    }

    cout<<dp[n][k]<<endl;
//    dp[0][0]=1;
//
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=k;j++)
//        {
//            if(i>=j)
//            dp[i][j] = dp[i-j][j] +dp[i-1][j-1];
//        }
//    }
//    cout<<dp[n][k]<<endl;
    return 0;
}
