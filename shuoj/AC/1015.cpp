#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;


int arr[100];
int DMAX[100][100][10];

int DMIN[100][100][10];
int n, m;
int dpmax(int l,int r,int s)
{
    if(r-l<s)return -1;
    int & d= DMAX [l%n][r%n][s];
    if(d!=-1)return d;
    if(s==1)
    {
        int ret=0;
        for(int i=l;i<r;i++)ret+=arr[i%n];
    //cout<<l<<" "<<r<<" " <<s<<' '<<ret%10<<endl;
        return d=ret%10;
    }
    int ans=0;
    for(int i=l+1;i<r;i++)
    {
        int r1 = dpmax(l,i,1);
        int r2 = dpmax(i,r,s-1);
        ans = max(ans,r1*r2);
    }
    //cout<<l<<" "<<r<<" " <<s<<' '<<ans<<endl;
    return d=ans;
}

int dpmin(int l,int r,int s)
{

    int &d = DMIN[l][r][s];
    if(d!=-1)return d;

    int ans=0x7ffffff ;
    if( s== 1)
    {
        int ret=0;
        for(int i=l;i<r;i++)ret+=arr[i%n];

        return d=ret%10;
    }
    else
    {
        for(int i=l+1;i<r;i++)
        {
            int r1 = dpmin(l,i,1);
            int r2= dpmin(i,r,s-1);
            ans = min(ans,r1*r2);
        }

    }
    return d=ans;

}

int main()
{

    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        arr[i]= ((arr[i]%10)+10)%10;
    }
    memset(DMIN,-1,sizeof(DMIN));
    memset(DMAX,-1,sizeof(DMAX));

    int MAX=0,MIN=0x7fffffff;
    for(int i=0;i<n;i++)
    {
        MAX = max(MAX,dpmax(i,n+i,m));
        MIN = min(MIN,dpmin(i,n+i,m));
    }

    cout<<MIN<<endl;
    cout<<MAX<<endl;

    return 0;
}
