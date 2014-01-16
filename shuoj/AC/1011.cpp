#include <iostream>
#include <cmath>
using namespace std;

int arr[30];

bool isprime(int x)
{

    for(int i=2;i<sqrt(x);i++)
    {
        if(x%i==0)return false;
    }
    return true;

}
 int n,k;
 int rec=0;
void dfs(int u,int d,int ans)
{
    if(d==k)
    {
        if(isprime(ans))rec++;
            return ;
    }

    for(int i=u+1;i<n;i++)
    {
        dfs(i,d+1,ans+arr[i]);
    }





}
int main()
{

    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>arr[i];

    for(int i=0;i<n;i++)
        dfs(i,1,arr[i]);


    cout<<rec<<endl;


    return 0;
}
