//Sat Jan 11 13:25:58 2014
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

char sw[100000+10];
int pH[100000+10];
int pT[100000+10];
int main()
{
    freopen("IN","r",stdin);
    std::ios::sync_with_stdio(false);
    int n;
    while(cin>>n && n!=0)
    {
        int sh=0,st=0;
        int ca=0,cb=0;
        cin.ignore();
        for(int i=0;i<n;i++)
        {
            cin>>sw[i];
            if(sw[i]=='H')sh++;
        }
        st= n-sh;

        //cout<<sw<<endl;
        if(st%2==1 || sh%2==1)cout<< "-1"<<endl;
        else
        {
            int ppt=0,pph=0;

                for(int j=0;j<n/2;j++)
                {
                    if(sw[j]=='H')pph++;
                    if(sw[j]=='T')ppt++;

                }
            int flag =false;
                if(ppt==st/2 && pph==sh/2){cout<<'1'<<endl<<n/2<<endl;flag=true;}

            if(!flag)
            for(int i=1;i+n/2<n;i++)
            {
                if(sw[i-1]=='H'){pph--;}
                else ppt--;

                if(sw[i+n/2-1]=='H')pph++;
                else ppt++;

                //cout<<"okok"<<i<<' '<<i+n/2-1<<' '<<pph<<' '<<ppt<<endl;
                if(ppt==st/2 && pph==sh/2){cout<<'2'<<endl<<i<<' '<<i+n/2<<endl;flag=true;break;}
            }

            if(!flag)
                cout<<'-1'<<endl;

        }

    }


    return 0;
}
