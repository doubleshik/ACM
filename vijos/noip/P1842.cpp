#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct match{
    long long  a,b,under;
    bool operator < (const match& x) const
    {
        return a<x.a;
    }
}M[100000+10];
long long T[100000+10];
long long  ans=0;
int n;
void merge_sort(match *A, int x,int y,long long *T)
{
    if(y-x>1)
    {
        int m = x+ (y-x)/2;
        int p= x , q= m , i = x;

        merge_sort(A,x,m,T);
        merge_sort(A,m,y,T);
        while(p<m || q < y )
        {
            if(q>=y || (p<m &&A[p].under <=A[q].under))
            {
                T[i++] = A[p++].under;
               // cout<<A[p].b<<" "<<A[q].b<<endl;
            }
            else
            {
                T[i++]=A[q++].under;
                //cout<<m<<p;
                ans+=m-p;
            }
        }
        for(i=x;i<y;i++)
        {
            A[i].under=T[i];
            //cout<<T[i]<<endl;
        }
        // for(int i=0;i<n;i++)cout<<A[i].b;
           // cout<<endl;
    }
}
int main()
{

    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&M[i].a);
        M[i].under=i;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&M[i].b);
    }
    sort(M,M+n);

    //for(int i=0;i<n;i++)cout<<M[i].b;
    merge_sort(M,0,n,T);
    cout<<ans%99999997;
    return 0;
}
