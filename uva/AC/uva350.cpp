#include <iostream>
#include <memory.h>
using namespace std;

const int maxn = 100000;
int cycle[maxn];
int repeat[maxn];

int main()
{
    int Z,L,I,M;
    int cnt,tmp,tst=0;
    while(cin>>Z>>L>>I>>M)
    {
        if(Z==0&&L==0&&I==0&&M==0)break;

        memset(cycle,0,sizeof(cycle));
        memset(repeat,0,sizeof(repeat));
        tst++;
        for(cnt=0,tmp =M;cnt<maxn&&repeat[tmp]==0;cnt++ )
        {
            repeat[tmp]=1;
            cycle[cnt]=tmp;
            tmp = (Z* tmp+L)%I;
        }

        if(tmp==M)
            cout<<"Case "<<tst<<": "<<cnt<<endl;
        else
        {
            int k=0;
            while(tmp!=cycle[++k]);

            cout<<"Case "<<tst<<": "<<cnt-k<<endl;

        }
    }

    return 0;
}
