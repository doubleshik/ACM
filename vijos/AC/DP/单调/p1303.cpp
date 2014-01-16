//Fri Jan 10 19:29:45 2014
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

int rock[30];
int pr=0;
int in[30];
int de[30];
int main()
{
    freopen("IN","r",stdin);
    char c;
    while(scanf("%d%c",&rock[pr++],&c)==2)
    {
        if(c=='\n')break;
    }

    for(int i=0;i<pr;i++){de[i]=1;}
    for(int i=0;i<pr;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(rock[i]<=rock[j])
            {
                de[i] = max(de[i],de[j]+1);
            }
        }
    }


     for(int i=0;i<pr;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(rock[i]>rock[j])
            {
                in[i] = max(in[i],in[j]+1);
            }
        }
    }
    int aa=0,ab=0;
    for(int i=0;i<pr;i++){aa=max(aa,de[i]); ab= max(ab,in[i]);}
    cout<<aa<<','<<ab<<endl;
    return 0;
}
