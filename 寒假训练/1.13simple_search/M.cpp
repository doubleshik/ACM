
    #include <cstdio>
    #include <cstring>
    using namespace std;

    int G[9][9];

    int judge(int x,int y,int k)
    {
        for(int i=0;i<9;i++)
        {
            if(G[x][i]==k)
            {
                return 0;
            }
        }
        for(int i=0;i<9;i++)
        {
            if(G[i][y]==k)
            return 0;
        }
        int m = x/3,n=y/3;
        for(int i=3*m;i<3*m+3;i++)
        {
            for(int j=3*n;j<3*n+3;j++)
            {
               if(G[i][j] == k)
                return 0;
            }
        }

        return 1;

    }
    int sign=0;

    int dfs(int n)
    {
        if(n<0){sign=1;return 0;}

        int x= n/9,y=n%9;
        if(G[x][y]!=0)
            dfs(n+1);
        else
        {
            int jud=0;
            for(int i=1;i<=9;i++)
            {
                if(judge(x,y,i))
                {
                    G[x][y] = i;
                    dfs(n-1);
                    if(sign) return 0;
                    G[x][y] = 0;
                }
            }
        }
        return 0;
    }
    void print()
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                printf("%d",G[i][j]);
            }
            printf("\n");
        }
    }
    int main()
    {
        freopen("IN","r",stdin);
        int tst;
        scanf("%d",&tst);
        while(tst--)
        {
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                {
                   scanf("%1d",&G[i][j]);
                }
            }
            dfs(80);
            print();
            sign=0;
            //memset(G,0,sizeof(G));
        }



        return 0;
    }
