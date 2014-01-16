//Sat Jan 11 18:55:27 2014
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

int TIAN,KE;
int cl[105][105];
int ans[105][110];

#define REP(i,N) for(int i=0;i<N;i++)

int dfs(int x,int r)
{
    if(ans[x][r]) return ans[x][r];

    if(x==KE)return 0;

    int &d = ans[x][r];

    d = dfs(x+1,r);

    for(int i=1;i<=r;i++)
    {
        d = max(d,dfs(x+1,r-i)+cl[x][i-1]);
    }
    return d;

}
int main()
{

    while(cin>>KE>>TIAN && KE+TIAN!=0)
    {
        REP(i,KE)REP(j,TIAN)
                cin>>cl[i][j];



        for(int i=1;i<=TIAN;i++)
        {
            for(int j=1;j<=KE;j++)
            {
                 ans[j][i] = ans[j-1][i];
                for(int k=1;k<=i;k++)
                {
                     ans[j][i] = max (ans[j][i], ans[j-1][i-k] +cl[j-1][k-1] );
                }

            }
        }




        cout<<ans[KE][TIAN]<<endl;


    }


    return 0;
}
