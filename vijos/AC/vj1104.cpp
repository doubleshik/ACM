//Sat Jan 11 21:11:17 2014
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
using namespace std;

int gv[105];
int gt[105];
int dp[105][1005];

int T,M;
int dfs(int x,int t)
{
    if(x<0 || t<0) return 0;
    int& d = dp[x][t];
    if(d)return d;


    if(gt[x-1] <=t )
    {
        d = max( dfs(x-1,t), dfs(x-1,t-gt[x-1])+gv[x-1] );
        return d;
    }
    else
        return dfs(x-1,t);

}
int main()
{
    freopen("IN","r",stdin);
    cin>>T>>M;

    for(int i=0;i<M;i++)
    {
        cin>>gt[i]>>gv[i];
    }
    cout<<dfs(M,T)<<endl;

    return 0;
}
