#include <cstdio>

int main()
{
    int row,line;
    while(scanf("%d %d",&row,&line)==2)
    {
        printf("%d\n",row*line-1);
    }

    return 0;
}
