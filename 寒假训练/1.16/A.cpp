//Thu Jan 16 08:42:48 2014
//Author:Minshik
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <memory.h>
#include <cctype>
#include <cmath>
#include <list>
#include <map>
using namespace std;


const int MAXN = 1000000+10;

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
}

bool check(int n)
{
    if(notprime[n])return false;
    int num=0;
    while(n)
    {
        num+= n%10;
        n/=10;
    }
    if(notprime[num])return false;

    return true;

}

int sum[MAXN];

void init()
{
    sum[0]=0;
    for(int i=1;i<MAXN;i++)
    {
        if(check(i))
        {
            sum[i]=1;
        }
        else sum[i]=0;
    }
    for(int i=1;i<MAXN;i++)
    {
        sum[i]+=sum[i-1];
    }

}

int main()
{
    int tst;
    cin>>tst;
    int L,R;
    prime();
    init();
    int cse=0;
    while(tst--)
    {
        cin>>L>>R;
        cout<<"Case #"<<++cse<<": "<<sum[R]-sum[L-1]<<endl;
    }


    return 0;
}
