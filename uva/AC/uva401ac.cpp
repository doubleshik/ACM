#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

const int maxn=1000;
char mirL[50]="ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
char mirR[50]="A   3  HIL JM O   2TUVWXY51SE Z  8 ";


char str[maxn];

int main()
{
    int P=1,M=1;


    while(scanf("%s",str)!=EOF)
    {
        P=1;M=1;
        int len=strlen(str)-1;
        for(int i=0;i<len/2+1;i++)
        {
            if(str[i]!=str[len-i])P=0;

            int mirror=0;
            for(int j=0;j<35;j++)
            {
                if(mirL[j]==str[i])
                {
                    if(mirR[j]!=str[len-i])
                    {
                        M=0;
                    }
                }
            }
        }

        if(!P&&!M)
            cout<<str<<" -- is not a palindrome."<<endl<<endl;

        if(P&&!M)
            cout<<str<<" -- is a regular palindrome."<<endl<<endl;
        if(!P&&M)
            cout<<str<<" -- is a mirrored string."<<endl<<endl;
        if(P&&M)
            cout<<str<<" -- is a mirrored palindrome."<<endl<<endl;
    }


    return 0;
}
