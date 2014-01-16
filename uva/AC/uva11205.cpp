#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


char B[200][20];
int flag [20] ;
int minn;
int all[200][20];
int subset(int n,int p,int cur)
{
    if(cur==p)
    {
        int ct=0;
        for(int i=0;i<p;i++)
        {
            if(flag[i])
            {
                for(int j=0;j<n;j++)
                {
                    B[j][ct] = all[j][i]+'0';
                }
                ct++;
            }
        }
        for(int i = 0; i<n; i++)
            for(int j=ct;j<p;j++)
                B[i][j] = 0;
        for(int j=0;j<n-1;j++)
        {
            for(int i=j+1;i<n;i++)
            {
                if(!strcmp(B[j],B[i]))
                    return 0;
            }
        }



        if(minn>ct)
        {
            minn=ct;
        }
        return 1;


    }

    flag [cur ]=0;
    subset(n,p,cur+1);
    flag[cur]=1;
    subset(n,p,cur+1);
    return 0;
}

int main()
{
    freopen("in.txt","r",stdin);
    int tst;
    cin>>tst;
    while(tst--)
    {
        int P,N;
        cin>>P>>N;

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<P;j++)
            {
                scanf("%d",&all[i][j]);
            }
        }
        minn=P;

        subset(N,P,0);
        cout<<minn<<endl;
    }


    return 0;
}
