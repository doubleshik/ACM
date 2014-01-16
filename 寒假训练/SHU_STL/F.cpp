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
using namespace std;

set<string> fin;
vector<string > a,b;
int main()
{
    freopen("IN","r",stdin);
    int tst;
    cin>>tst;
    int cse=0;

    while(tst--)
    {
        cout<<"Case "<<++cse<<": ";
        int n,m;
        cin>>n>>m;
        cin.ignore();
        string tmp;
        for(int i=0;i<n;i++)
        {
            getline(cin,tmp,'\n');
            a.push_back(tmp);
        }

        for(int i=0;i<m;i++)
        {

            getline(cin,tmp,'\n');
            b.push_back(tmp);
        }
        string now;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                now=a[i];
             //   cout<<b[j];
                now+=b[j];
               // cout<<now;
                if(!fin.count(now))
                {
                    fin.insert(now);
                }

            }
        }
        cout<<fin.size()<<endl;
        a.clear();
        b.clear();
        fin.clear();

    }


    return 0;
}
