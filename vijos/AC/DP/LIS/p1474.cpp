    //Fri Jan 10 18:31:09 2014
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
    using namespace std;

    struct NN
    {
        int n;
        int h;
        bool operator < (const NN& x)const
        { return h<x.h;}
    }G[5000];

    long long ans[5000];
    int n;
    int dist(int a,int b)
    {
        int x1 = G[a].n/n,y1=G[a].n%n;
        int x2 = G[b].n/n,y2=G[b].n%n;
        return pow(abs(x1-x2)+abs(y1-y2),2);
    }
    int main()
    {
        freopen("IN","r",stdin);


        cin>>n;
        int s,e;
        for(int i=0;i<n*n;i++)
        {
            cin>>G[i].h;
            G[i].n=i;
            if(G[i].h==1){e=i;}
            if(G[i].h==n*n){s=i;}
        }

        sort(G,G+n*n);
        for(int i=0;i<n*n;i++) ans[i] = dist(i,0);

        for(int i=1;i<n*n;i++)
        {
            for(int j=0;j<i;j++)
            {
                ans[i] = max(ans[i],ans[j]+dist(i,j));
            }
        }
        cout<<ans[n*n-1]<<endl;

        return 0;
    }
