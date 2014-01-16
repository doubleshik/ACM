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
#define M 12

    int  n,k;
struct matrix
{
    int v[M][M];
    matrix operator * (matrix t);
    matrix pow(int t);
}a;
matrix matrix::operator*(matrix t)
{
    int tmpans;
    matrix tmp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            tmpans=0;
            for(int k=0;k<n;k++)
            {
                tmpans = (tmpans+t.v[i][k]*(*this).v[k][j])%9973;
            }
            tmp.v[i][j] = tmpans;

        }
    }
    return tmp;
}

matrix matrix:: pow(int t)
{
    if( t== 1) return *this;

    matrix tmp = (*this)*(*this);
    if(t&1) return tmp.pow(t>>1)*(*this);
    else return tmp.pow(t>>1);
}

int main()
{
    freopen("IN","r",stdin);
    int tst;
    cin>>tst;
    while(tst--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a.v[i][j];
            }
        }
        matrix e;
        e=a.pow(k);
        int ans=0;
        for(int i=0;i<n;i++)ans+= e.v[i][i];
        cout<<ans%9973<<endl;
    }


    return 0;
}
