#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int tst;
    int num;
    cin>>tst;
    int cnt=1;

    while(tst--)
    {
        int times=0;
        cin>>num;
        for(int i=2;i<num;i++)
        {
            if(num%i==0)
            {
                if(times==0)
                {
                    printf("Case #%d: %d = %d * %d ",cnt,num,i,num/i);
                    times++;
                }
                else
                {
                    printf("= %d * %d\n",i,num/i);
                    break;
                }
            }
        }

        cnt++;
    }

    return 0;
}
