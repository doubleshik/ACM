#include <iostream>
using namespace std;

int tt[200];
int v[200];
int dp[2000][200];
//
//int dfs(int T,int M)
//{
//    int &d = dp[T][M];
//
//
//    if(d)return d;
//    if(M==0)return 0;
//
//    d = dfs(T,M-1);
//    if(T-tt[M]>=0)
//        d = max(d, dfs(T-tt[M],M-1)+v[M]);
//
//    return d;
//
//
//}
int main()
{
    int T,M;
    cin>>T>>M;

    for(int i=1;i<=M;i++)
    {
        cin>>tt[i]>>v[i];
    }
//
//    cout<<dfs(T,M)<<endl;

    for(int m=1;m<=M;m++)
    {
        for(int t=0 ;t<=T;t++)
        {
            if(t-tt[m]<0)
                dp[t][m] = dp[t][m-1];
            else
            dp[t][m] = max( dp[t][m-1],dp[t-tt[m]][m-1]+v[m]  );
        }
    }
    cout<<dp[T][M]<<endl;
    return 0;
}
