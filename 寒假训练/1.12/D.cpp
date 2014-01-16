//Sun Jan 12 12:21:58 2014
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


int main()
{

    int tst;
    scanf("%d",&tst);
    while(tst--)
    {
        int N;
        scanf("%d",&N);
        double MAX=0;
        double now = 0;
        double sum=0;
        for(int i=0;i<N;i++)
        {
            scanf("%lf",&now);
            MAX=max(MAX,now);
            sum+=now;
        }
        if(MAX<=sum-MAX+1)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }

    }

    return 0;
}
