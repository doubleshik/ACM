#include <iostream>
//#include <iomainp>
#include <cstdio>
#include <string.h>
using namespace std;

int N,k,m;
int per[21];
int main()
{

    scanf("%d %d %d",&N,&k,&m);

    while(!(N==0&&k==0&&m==0))
    {
        int size = N;
        for(int i=0;i<N;i++)
        {
            per[i]=i+1;
        }

        int one=0,two=N-1;
        while(size>0)
        {
             for(int i=1;i<k;i++)
             {
                 one=(one+1)%N;
                 if(!per[one])i--;
             }
             for(int i=1;i<m;i++)
             {
                 two = (N+two-1)%N;
                 if(!per[two])i--;
             }
             if(per[one])
             {
                 printf("%3d",per[one]);
                 per[one]=0;
                 size--;
             }

             if(per[two])
             {
                 printf("%3d",per[two]);
                 per[two]=0;
                 size--;
             }

             for(int i=0;i<N;i++)
             {
                 one=(one+1)%N;
                 if(per[one])break;
             }

             for(int i=0;i<N;i++)
             {
                 two=(N+two-1)%N;
                 if(per[two])break;
             }
             if(size)printf(",");
             else
                printf("\n");
        }

        scanf("%d %d %d",&N,&k,&m);

    }

    return 0;
}
