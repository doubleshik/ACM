#include <iostream>
using namespace std;

const int MAXN = 1000010;

bool notprime[MAXN];


void prime()
{
    memset(notprime,false,sizeof(notprime));
    notprime[0] = notprime[1] = true;
    for(int  i =2;i<MAXN; i++)
    {
        if(!notprime[i])

        {
            if(i>MAXN/i) continue;
            for(int j=i*i;j<MAXN;j+=i)
                notprime[j]=true;
        }
    }
}//eratho 筛法

int prime[MAX+10];

void getprime()
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i<MAXN;i++)
    {
        if(prime[i]==0)
        {
            prime[++prime[0]] = i;
        }
        for(int j=1;j<=prime[0];j++)
        {
            if(prime[i] >= MAXN/i)break;
            prime[i * prime[j] ] =1;
            if(i%prime[j]==0)break;//o(n) 保证一次筛选
        }
    }

    return 0;
}   // euler筛法// 方便求出 质数分解的指数



void get()
{
    memset(prime,0,sizeof(prime));


}

int main()
{

}
