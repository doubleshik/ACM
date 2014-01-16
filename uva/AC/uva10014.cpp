#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
    int tst;

    cin>>tst;

    double a0,ann,c;
    while(tst--)
    {
        int n;
        cin>>n>>a0>>ann;

        double ans = 0;
        ans = n*a0/(n+1)+ann/(n+1);

        for(int i=1;i<=n;i++)
        {
            cin>>c;
            ans -= (n+1-i)*2*c/(n+1);
        }


        printf("%.2lf\n",ans);
        if(tst)printf("\n");
    }


    return 0;
}
