#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

#define PI acos(-1)

int main()
{
    double a,b,s,m,n;
    double angle,v;
    while(cin>>a>>b>>s>>m>>n)
    {
        if(a+b+s+m+n==0)break;
        angle =atan((b*n)/(a*m))*180/PI;
        v=sqrt(b*n*b*n+a*m*a*m)/s;
        printf("%.2lf %.2lf\n",angle,v);

    }


    return 0;
}
