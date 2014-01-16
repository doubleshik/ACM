#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

const int maxn = 1000000;
short vis[maxn];
void prime()
{
    for(int i=2;i<=maxn;i++)
    {
        for(int j=i*2;j<=maxn;j*=2)
        {
            vis[j]=1;
        }
    }
}
int main()
{
    long long num;
    prime();
    while(scanf("%lld",&num))
    {
        if(num<0)break;

        long long temp=num;
        for(long long i=2;i<sqrt(double(num));i++)
        {
            while(num%i==0)
            {
                printf("    %lld\n",i);
                num/=i;
            }

        }
        if(num==temp)
            printf("    %lld\n",num);
        else if(num!=0)
        {
            printf("    %lld\n",num);
        }

        cout<<endl;

    }

    return 0;
}
