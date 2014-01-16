#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 300000+10;
int a[MAXN];
int b[MAXN];
int pb=1;


int main()
{

   // freopen("IN","r",stdin);

    int N,K;
    scanf("%d%d",&N,&K);

    for(int i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
    int lb=0;
    for(int i=0;i<K-1;i++)
    {
        int pos = lower_bound(b,b+pb,a[i])-b;

        if(pb==0|| pos==pb||  a[i] < b[pos] )
        {
            b[pb++] = a[i];
        }
    }

    int pos = lower_bound ( b, b+pb,a[K-1])-b;
    if(pos!=pb)pb=pos;
    b[pb++]= a[K-1];


    lb = pb-1;
    for(int i=K;i<N;i++)
    {
        int pos = lower_bound(b,b+pb,a[i])-b;
        if( pos != lb &&(a[i] < b[pos] || pb==0 || pos==pb))

        {
            b[pb++] = a[i];
        }
    }
    cout<<pb-1<<endl;


    return 0;
}
