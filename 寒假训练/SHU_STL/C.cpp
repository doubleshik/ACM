//Sat Jan 11 23:30:37 2014
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

const int MAX = 5000000;
int prime[MAX];

int PP()
{
    for(int i=2;i<=MAX;i++)
    {
        if(!prime[i]) prime[++prime[0]] =i;

        for(int j=1;j<=prime[0] && prime[j]<=MAX/i;j++)
        {
            prime[prime[j]*i] =1;
            if(i%prime[j]==0) break;
        }
    }

}

//orz 神方法 mobai

int main()
{
    PP();
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        int flag=0;
        for(int i=1;i<prime[0];i++)
        {
            int t=lower_bound(prime+1,prime+prime[0],prime[i]+x)-prime;
            if(prime[t]==prime[i]+x)
            {
                printf("%d %d\n",prime[t],prime[i]);
                flag=1;
                break;
            }
        }
        if(!flag)

        {
            printf("FAIL\n");
        }

    }


    return 0;
}
