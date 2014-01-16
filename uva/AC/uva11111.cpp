#include <iostream>
#include <cmath>
#include <stack>
#include <cstdio>
#include <stdlib.h>
#include <memory.h>
using namespace std;

int arr[30000];
int p=0;
int solve()
{
    int stack[30000];
    int sum[30000];
    memset(stack,0,sizeof(stack));
    memset(sum,0,sizeof(sum));
    int top=0;
    for(int i=0;i<p;i++)
    {
        if(arr[i]<0)
        {
            sum[top]=sum[top]-arr[i];
            top++;
            stack[top] = abs(arr[i]);
        }
        else
        {
            if(arr[i]!= stack[top])return 0;
            if(sum[top]>=arr[i])return 0;
            sum[top]=0;
            top--;
        }
    }
    return 1;
}
int main()
{
    char tc;
    int ti;
    p=0;
    int flag=0;
    while(scanf("%d",&ti)!=EOF)
    {
        while(1)
        {
            arr[p++]=ti;
            tc=getchar();
            if(tc=='\n')break;
            scanf("%d",&ti);
        }
        if(p%2)flag=0;
        else
            flag = solve();
        if(flag)
            cout<<":-) Matrioshka!"<<endl;
        else
            cout<<":-( Try again."<<endl;

        p=0;
    }
    return 0;
}
