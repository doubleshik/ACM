#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;


int main()
{
    int N;

    while(scanf("%d",&N)!=EOF)
    {
        int ans=1;
        for(int i=1;i<=N;i++)
        {
            ans*=i;
            while (ans%10==0 )
                ans/=10;
            ans=ans%100000;
        }
        printf("%5d -> %d\n",N,ans%10);
    }

    return 0;
}
