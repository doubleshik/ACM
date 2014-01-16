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

list<char> L;
int main()
{
    freopen("IN","r",stdin);
    string buf;
    while(getline(cin,buf))
    {
        list<char>::iterator iv = L.begin();

        for(int i=0;i<buf.length();i++)
        {
            if(buf[i]=='[')
            {
                iv = L.begin();

            }
            else if(buf[i]==']')
            {
                iv = L.end();
            }
            else
            {
                L.insert(iv,buf[i]);
            }

        }

        for(iv = L.begin();iv!=L.end();iv++)
        {
            cout<<*iv;
        }
        cout<<endl;

        L.clear();
    }

    return 0;
}
