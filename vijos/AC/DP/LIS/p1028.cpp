#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector <string > w;
int ans[5000];
int main()
{
    freopen("IN","r",stdin);

    int N;
    cin>>N;
    //cin.ignore();
    for(int i=0;i<N;i++)
    {
        string tmp;
        cin>>tmp;
        w.push_back(tmp);
    }

    for(int i=0;i<N;i++)ans[i]=1;

    for(int i=1;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {
            if( w[i].find(w[j]) !=string::npos )
                ans[i] = max( ans[i], ans[j]+1);

        }

    }
    int MAX = -0xffff;
    for(int i=0;i<N;i++)
    {
        MAX = max( MAX, ans[i]);
    }
    cout<<MAX<<endl;
    return 0;
}
