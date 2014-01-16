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

int n;

struct P
{
    int num;
    int fa;
    P(){}
    P(int a,int b):num(a),fa(b){}

};

int vis[1000];
P que[500];
int front,rear;
int bfs()
{
    front=0,rear=1;
    que[front]= P(1,front);

    while(front<rear)
    {
        P tmp  = que[front];

        int d= tmp.num%n;

        if(d==0)
        {
            que[front].num%=10;
            return front;
        }
        if(!vis[d])
        {
            que[rear] = P(  d*10+1,front  );
            rear++;
            que[rear] = P(d*10 ,front);
            rear++;
            vis[d]=1;
            que[front].num %=10;
        }
        front++;
    }

}

int ans[500];
int pa=0;
int main()
{

    while(cin>>n&&n!=0)
    {
        pa=0;
        int x=bfs();
        while(que[x].fa != x )
        {
            ans[pa++] = que[x].num;
            x=que[x].fa;
        }
        cout<<"1";
        for(int i=pa-1;i>=0;i--)
        {
            cout<<ans[i];
        }
        cout<<endl;

        memset(vis,0,sizeof(vis));
    }


    return 0;
}
