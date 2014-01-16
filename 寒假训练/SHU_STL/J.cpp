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

stack< char > vv;
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    char exp[5000];
    while(n--)
    {
        cin.getline(exp,5000);
        if(strcmp(exp,"\n")==0)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            for(int i=0;i<strlen(exp);i++)
            {
                if(vv.empty())vv.push(exp[i]);
                //cout<<vv.top()<<endl;
                else if((vv.top()=='(' && exp[i]==')') || (vv.top()=='['&&exp[i]==']'))
                {
                    vv.pop();
                }
                else
                {
                    vv.push(exp[i]);
                }
            }

            if(!vv.empty())cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
            while(!vv.empty())vv.pop();
        }
    }


    return 0;
}
