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
#include <string>
using namespace std;

map<string , int> vv;

vector <string> ss;
vector <string> ans;
int main()
{
    freopen("IN","r",stdin);

    string s;
    while(cin>>s)
    {
        ss.push_back(s);
        vv[s]=1;
    }
    for(int i=0;i<ss.size();i++)
    {
        for(int j=1;j<ss[i].length();j++)
        {
            string l = ss[i].substr(0,j);
            string r = ss[i].substr(j);
            //cout<<l<<' '<<r<<endl;
            if(vv[l]==1 && vv[r]==1)
            {
                ans.push_back(ss[i]);
                break;
            }
        }

    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
