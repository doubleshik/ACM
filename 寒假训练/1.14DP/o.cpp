#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

#define MAX 10000+10
struct G
{
    int dead;
    int prof;

    bool operator < (const G &x) const{
        return dead> x.dead;
    }

}good[MAX];

priority_queue < int > q;
int main()
{
    freopen("IN","r",stdin);
    int  n;

    while(cin>>n)
    {
        int T= 0;
        for(int i=0;i<n;i++)
        {
            cin>>good[i].prof>>good[i].dead;
            T = max(T, good[i].dead);
        }
        sort(good,good+n);

        int d = good[0].dead;
        int ans=0;
        int i=0;
        for(int t= T; t>=1;t--)
        {
            while(i<n && good[i].dead>=t)
            {
                q.push(good[i].prof);
                i++;
            }
            if(!q.empty())
            {
                ans+= q.top();
                q.pop();
            }
        }
        cout<<ans<<endl;
        while(!q.empty())
            q.pop();
    }


    return 0;
}
