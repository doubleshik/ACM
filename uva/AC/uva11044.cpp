#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int tst;
    scanf("%d\n",&tst);
    while(tst--)
    {
        int row,line;
        scanf("%d%d\n",&row,&line);
       printf("%d\n",(row/3)*(line/3));
    }

    return 0;
}
