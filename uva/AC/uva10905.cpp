#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(string a,string b)
{
    return a+b>b+a;
}

void solve(int n)
{
    string a[100];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
        cout<<a[i];
    cout<<endl;


}


int main()
{
    int n;
    while(cin>>n && n)
    {
        solve(n);
    }

}
