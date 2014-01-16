//Wed Jan  1 16:34:55 2014
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

const int maxn = 1000+10;
int N,G;
int P[maxn];
int W[maxn];
int Cap[maxn];
int F[maxn];
int input()
{
    cin>>N;
    for(int i=1;i<=N;i++){cin>>P[i];cin>>W[i];}
    cin>>G;
    int tmp;
    for(int i=0;i<G;i++){cin>>Cap[i];}
    return 0;
}
int main()
{
    int tst;
    cin>>tst;
    while(tst--)
    {
        input();

        int AAA=0;
        for(int k=0;k<G;k++)
        {
            for(int i=1;i<=N;i++)
            {
                for(int v=Cap[k];v>=W[i];v--)
                {
                    if(v>=W[i])
                        F[v] = max( F[v], F[v-W[i]]+P[i]);
                }
            }

            AAA+=F[Cap[k] ];
            for(int i=0;i<=Cap[k];i++)
                F[i]=0;
        }
        cout<<AAA<<endl;
    }


    return 0;
}
