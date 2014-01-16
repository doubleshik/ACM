#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

#define lowbit(x) ((-x)&x)
int tmp;
int N;
int C[50000+10];
int sum(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=C[x]; x-=lowbit(x);
    }
    return ret;

}
void add(int x,int d)
{
    while(x<=N)
    {
        C[x]+=d; x+=lowbit(x);
    }
}


int main()
{

    int tst;
    scanf("%d",&tst);
    char cmd[10];
    int cse=0;
    while(tst--)
    {
        printf("Case %d:\n",++cse);
            scanf("%d",&N);
            for(int i=1;i<=N;i++)
            {
                scanf("%d",&tmp);
                add(i,tmp);
            }
            while(scanf("%s",cmd))
            {
                if(cmd[0]=='E')break;
                int a,b;
                scanf("%d %d",&a,&b);
                if(cmd[0]=='Q')
                {
                    printf("%d\n",sum(b)-sum(a-1));
                }
                else if(cmd[0]=='A')
                {
                    add(a,b);
                }
                else if(cmd[0]=='S')
                {
                    add(a,-b);
                }
                getchar();
            }
            memset(C,0,sizeof(C));
    }


    return 0;
}


