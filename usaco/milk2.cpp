/*
ID:doubles3
PROB:milk2
LANG:C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 5000+10;
int n;
int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    map<int,int>time;
    scanf("%d",&n);
    int s,e;
    while(n--)
    {
        scanf("%d %d",&s,&e);
        time.insert(pair<int,int>(s,e));

    }
    map<int,int>::iterator iv = time.begin();

    int tmpbegin = iv->first;
    int tmpend = iv->second;
    int maxdo=0,maxstop=0;
    for(iv=time.begin();iv!=time.end();iv++)
    {
        int s = iv->first;
        int e = iv->second;
        if(s<=tmpend)
        {
            if(tmpend<e)
            {
                tmpend = e;
            }
            if(maxdo<tmpend-tmpbegin) maxdo = tmpend-tmpbegin;

        }
        else
        {

            if(maxstop < s - tmpend)
                maxstop = s-tmpend;

            tmpbegin = s;
            tmpend = e;
        }
    }
    printf("%d %d\n",maxdo,maxstop);
    return 0;
}
