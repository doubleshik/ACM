#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char str1[2000];
char str2[2000];
int d[2000][2000];
int main()
{
    while(gets(str1))
    {
        gets(str2);
        int len1= strlen(str1);
        int len2= strlen(str2);

        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(str1[i-1]== str2[j-1])
                {
                    d[i][j]  = d[i-1][j-1]+1;
                }
                else
                {
                    d[i][j] = max (d[i-1][j],d[i][j-1]);
                }
            }

        }
        cout<<d[len1][len2]<<endl;
        memset(d,0,sizeof(d));
    }


    return 0;
}
