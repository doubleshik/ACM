#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
    char c;
    int i=128,ans=0;
    while(scanf("%c",&c)!=EOF)
    {
        if(c=='\n')
        {
            if(!i)printf("%c",ans);
            i=128;
            ans=0;
            continue;
        }
        if(c=='o')
        {
            ans+=i;
            i/=2;
        }
        if(c==' ')
        {
            i/=2;
        }
    }


    return 0;
}
