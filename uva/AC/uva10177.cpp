#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

const int maxn = 105;
unsigned long long s2[maxn],r2[maxn],s3[maxn],r3[maxn],s4[maxn],r4[maxn];
int main()
{
    long long  n;


    s2[0]=0;s3[0]=0;s4[0]=0;

    for(unsigned long long i=1;i<=100;i++)
    {
        s2[i]=s2[i-1]+i*i;
        r2[i]=pow((i+1)*i/2,2)-s2[i];

        s3[i]=s3[i-1]+i*i*i;
        r3[i]=pow(i*(i+1)/2,3)-s3[i];

        s4[i]=s4[i-1]+i*i*i*i;
        r4[i]=pow(i*(i+1)/2,4)-s4[i];

    }

    while(scanf("%lld",&n)!=EOF)
    {
         printf("%llu %llu %llu %llu %llu %llu\n",s2[n],r2[n],s3[n],r3[n],s4[n],r4[n]);
    }
    return 0;
}
