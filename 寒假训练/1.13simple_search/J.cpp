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

#define MAX 1000000
int A,B,C;
struct ST
{
    int a,b;
    string pp;
    int step;
    ST(int c,int d,string s,int e): a(c),b(d),pp(s),step(e){}
    ST(){}
};

ST que[MAX];

int fa[MAX];
int vis[200][200];
int bfs()
{
    int front=0,rear=1;
    que[front]=ST(0,0,"stat",0);
    fa[front] = front;
    vis[0][0]=1;
    while(front<rear)
    {
        if(que[front].a == C || que[front].b==C)
        {
            //cout<<fa[front]<<endl;
            return front;
        }

        int a=que[front].a,b=que[front].b;

     //   cout<<fa[front]<<" "<<que[fa[front]].a<<" "<<que[fa[front]].b<<" "<< ' '<<front<< ' '<<que[front].pp<<' '<<a<<' '<<b <<endl;


        if(a!=A &&!vis[A][b])
        {
            que[rear] = ST(A,b,"FILL(1)",que[front].step+1);
            fa[rear] = front;
            rear++;
            vis[A][b]=1;
        }

        if(b!=B && !vis[a][B])
        {

            que[rear] = ST(a,B,"FILL(2)",que[front].step+1);
            fa[rear]=front;
            rear++;
            vis[a][B]=1;
        }
        if(a!=0&&!vis[0][b])
        {

            que[rear] = ST(0,b,"DROP(1)",que[front].step+1);
            fa[rear] = front;
            rear++;
            vis[0][b]=1;
        }
        if(b!=0&&!vis[a][0])
        {

            que[rear] = ST(a,0,"DROP(2)",que[front].step+1);
            fa[rear] = front;
            rear++;
            vis[a][0]=1;
        }

        if(a>B-b)
        {
            if(!vis[a-(B-b)][B])
            {
                que[rear] = ST(a-(B-b),B,"POUR(1,2)",que[front].step+1);
                fa[rear++]=front;
                vis[a-(B-b)][B]=1;
            }
        }
        else if(a<B-b &&a!=0)
        {
            if(!vis[0][b+a])
            {
                que[rear] = ST(0,b+a,"POUR(1,2)",que[front].step+1);
                fa[rear++]=front;
                vis[0][b+a]=1;
            }
        }

        if(b>A-a)
        {
            if(!vis[A][b-A+a])
            {
                que[rear] = ST(A,b-(A-a),"POUR(2,1)",que[front].step+1);
                fa[rear++]= front;
                vis[A][b-A+a]=1;
            }
        }
        else if(b<A-a && b!=0)
        {
            if(!vis[a+b][0])
            {
                que[rear] = ST(a+b,0,"POUR(2,1)",que[front].step+1);
                fa[rear++]=front;
                vis[a+b][0]=1;
            }
        }

        front++;
    }
    return -1;

}

int main()
{

   // freopen("IN","r",stdin);
    cin>>A>>B>>C;
   // freopen("OUT","w",stdout);
    int k = bfs();

    if(k==-1)
    {
        cout<<"impossible"<<endl;
        return 0;
    }
    stack<string> ans;
    cout<<que[k].step<<endl;
    while(fa[k]!=k)
    {
        ans.push(que[k].pp);
        k=fa[k];
    }

    while(!ans.empty())
    {
        string s = ans.top();
        cout<<s<<endl;
        ans.pop();
    }

    return 0;
}
