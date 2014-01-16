#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <memory.h>
#include <malloc.h>
#include <math.h>
#include <cstdio>
using namespace std;

const int maxn = 900;
int f[maxn];
int fn[maxn];
int p=0;

void div(long long num)
{
        int many=0;
        memset(f,0,sizeof(f));
        memset(fn,0,sizeof(fn));
        p=-1;
        for(long long i=2;i<=num;i++)
        {
            while(num%i==0)
            {
                if(f[p]==i)
                {
                    fn[p]++;
                }
                else
                {
                    p++;
                    f[p]=i;
                    fn[p]++;
                }
                num/=i;
            }
    }
}
int main()
{
    long long num,base;
    int numn[maxn];
    while(cin>>num>>base)
    {
        div(base);
        memset(numn,0,sizeof(numn));

        int pn=0;
        for(int i=1;i<=num;i++)
        {
            int temp=i;
            for(int j=0;j<=p;j++)
            {
                while(temp%f[j]==0)
                {
                    numn[j]++;
                    temp/=f[j];
                }
            }
        }

        long long MIN=LONG_LONG_MAX;
        for(int i=0;i<=p;i++)
        {
            numn[i]/=fn[i];
            if(numn[i]<MIN)
                MIN=numn[i];
        }


        double digits=0;
        for(int i=1;i<=num;i++)
        {
            digits =digits+ log10(i);
        }
        digits/=log10(base);

        if (digits - floor(digits) < 1e-10)
            digits ++;
        else
            digits = floor(digits+ 1);

        printf("%lld %.0f\n",MIN,digits);
    }
    return 0;
}
