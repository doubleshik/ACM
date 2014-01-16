#include <cstdio>
#include <cmath>
int main()
{
    int year;
    while(scanf("%d",&year)==1)
    {
        if(year==0)break;
        year-=1960;
        year = (year-year%10)/10;
        int  word=1;
        for( long long  i=1;i<=year;i++)
            word*=2;

        word*=4;

        int ans=1;
        double sum=0;
        while(1)
        {
            sum+=log(ans)/log(2);
            if(word<=sum)break;
            else
                ans++;
        }
        printf("%d\n",ans-1);

    }


    return 0;
}
