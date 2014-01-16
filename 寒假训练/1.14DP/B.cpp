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
int G[101][101];
int dp[105][105];



int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>G[i][j];
        }
    }



    for(int p=0;p<N;p++)
    {
        for(int q=0;q<N;q++)
        {
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    dp[i+p][j+q] =

                }

            }
        }
    }
    return 0;
}
