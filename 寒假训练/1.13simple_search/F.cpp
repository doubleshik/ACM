    //Mon Jan 13 13:04:07 2014
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


    #define MAX 100000


    int vis[100000+10];
    struct P
    {
        int x,time;
        P(int a,int b): x(a) ,time(b){}
    };

    int N,K;
    void bfs()
    {
        queue<P> q;
        q.push(P(N,0));
        vis[N]=1;
        while(!q.empty())
        {
            P tmp = q.front();
            if(tmp.x == K)
            {
                cout<<tmp.time<<endl;
                return;
            }
            int d = tmp.x;
            if(d+1<=MAX && !vis[d+1])
            {
                q.push(P(d+1,tmp.time+1));
                vis[d+1]=1;
            }
            if(d-1>=0&& !vis[d-1])
            {
                q.push(P(d-1,tmp.time+1));
                vis[d-1]=1;
            }
            if(2*d<=MAX&& !vis[2*d])
            {
                q.push(P(2*d,tmp.time+1));
                vis[2*d]=1;
            }
            q.pop();
        }
        return ;

    }

    int main()
    {
        cin>>N>>K;

        bfs();


        return 0;
    }
