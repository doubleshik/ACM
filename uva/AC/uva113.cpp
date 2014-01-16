#include <cstdio>
#include <iostream>
#include <limits.h>
#include <cmath>

using namespace std;
int main()
{

    double a,b;
    double ans=0;
    while(scanf("%lf %lf",&a,&b)!=EOF)
    {

         printf("%.lf\n", pow(b, 1/a));
       }


    return 0;
}
