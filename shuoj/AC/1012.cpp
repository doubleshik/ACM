#include <iostream>
#include <cstdio>
using namespace std;

char dig[40];
int ra[20],rb[20];
int main()
{
    char c;
    cin>>c;
    int pd=1;
    dig[0]= c-'0';
    while(c!=' ')
    {
        cin>>c;
        dig[pd++] = c-'0';
    }

    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>ra[i]>>rb[i];
    }

    for(int i=0;i<pd;i++)
    {

    }


    return 0;
}
