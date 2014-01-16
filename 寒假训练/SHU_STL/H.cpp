//Sat Jan 11 23:30:37 2014
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

map<string , string> dict;

char s1[1000],s2[1000];

string a,b;
int main()
{
   // freopen("IN","r",stdin);

    while(1)
    {
        fgets(s1,sizeof(s1),stdin);
        if(strcmp(s1,"\n")==0) break;
        char a[1000],b[1000];
        sscanf(s1,"%s%s",a,b);

        dict[b] =a;
    }

    while(cin>>s1)
    {
        if(dict.count(s1))
            cout<<dict[s1]<<endl;
        else
            cout<<"eh"<<endl;
    }

    return 0;
}
