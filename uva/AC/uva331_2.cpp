#include <iostream>
#include <set>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;


int A[10];
int B[10];
int n;
int ans=0;
void dfs()
{
    if(memcmp(A,B,sizeof(A))==0)
    {
        ans++;
        return;
    }

    for(int i=0;i<n-1;i++)
    {
        if(B[i]>B[i+1])
        {
            swap(B[i],B[i+1]);
            dfs();
            swap(B[i],B[i+1]);
        }
    }

}
int main()
{
   // freopen("in.txt","r",stdin);
    int cst=0;
    while(cin>>n && n!=0)
    {

        for(int i=0;i<n;i++)
        {
            cin>>A[i];
        }
        memcpy(B,A,sizeof(B));

        sort(A,A+n);
        ans=0;
        if(memcmp(A,B,sizeof(A)))
        {
            dfs();
        }
        cout<<"There are "<<ans<<" swap maps for input data set "<<++cst<<"."<<endl;
    }

    return 0;
}
