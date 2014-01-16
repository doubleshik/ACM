#include <iostream>
#include <cstdio>
#include <limits.h>
using namespace std;

int ans=0;
int gcd(int a,int b)
{
    if(b==0)
    {
        ans=a;
        return 0;
    }
    if(a<b)
    {
        int temp;
        temp=a;
        a=b;
        b=temp;
    }
    gcd(b,a%b);
    return 0;
}

int main()
{
    int S,M;
    while(scanf("%d %d",&S,&M)!=EOF)
    {
        gcd(S,M);
        if(ans==1)printf("%10d%10d    Good Choice\n\n",S,M);
        else  printf("%10d%10d    Bad Choice\n\n",S,M);

        ans=0;
    }
    return 0;
}
