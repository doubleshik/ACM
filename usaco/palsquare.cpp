/*

ID:doubles3
PROB:palsquare
LANG:C++

*/



#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

bool judge(int b,int base)
{

    int tmp[2000];
    int a=b*b;
    int p=0;
    while(a)
    {
        tmp[p++]=a%base;
        a/=base;
    }

    for(int i=p-1;i>=(p/2);i--)
    {
        if(tmp[i] != tmp[p-i-1])return false;
    }

    int org[2000]={0};
    int po=0;
    while(b)
    {
        org[po++]=b%base;
        b/=base;
    }
    for(int i=po-1;i>=0;i--)
    {
        if(org[i]>=10)
        {
            printf("%c",'A'+org[i]-10);
        }
        else
            printf("%d",org[i]);
    }
    printf(" ");


    for(int i=p-1;i>=0;i--)
    {
        if(tmp[i]>=10)
        {
            printf("%c",'A'+tmp[i]-10);
        }
        else
            printf("%d",tmp[i]);
    }
    printf("\n");

    return true;

}

int main()
{
    freopen("palsquare.in","r",stdin);

    freopen("palsquare.out","w",stdout);
    int base;
    scanf("%d",&base);


    for(int i=1;i<=300;i++)
    {
        judge(i,base);
    }


    return 0;
}
