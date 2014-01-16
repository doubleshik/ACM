#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
char G[5][5];
int n;
bool check(int x,int y)
{
    int cnt=0;
    for(int i=0;i<x;i++)
    {
        if(G[i][y]=='@')
        {
            cnt++;
        }
        else if(G[i][y] == 'X')cnt=0;
    }
    if(cnt)return false;
    for(int i=n-1;i>=x+1;i--)
    {
        if(G[i][y]=='@')
        {
            cnt++;
        }
        else if(G[i][y] == 'X')cnt=0;
    }
    if(cnt)return false;

    for(int i=0;i<y;i++)
    {
        if(G[x][i]=='@')
        {
            cnt++;
        }
        else if(G[x][i] == 'X')cnt=0;
    }
    if(cnt)return false;
    for(int i=n-1;i>=y+1;i--)
    {
        if(G[x][i]=='@')
        {
            cnt++;
        }
        else if(G[x][i] == 'X')cnt=0;
    }
    if(cnt)return false;

    return true;
}

int ans=0;
void dfs(int x,int y,int tmp)
{

    if(check(x,y))
    {
        tmp++;
        G[x][y]='@';


        if(tmp>ans)
        {
            ans  = tmp;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(G[i][j]=='.')
                    dfs(i,j,tmp);
            }
        }
        G[x][y]='.';
    }


}


int main()
{

    while(cin>>n && n!=0)
    {
        getchar();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                 G[i][j]=getchar();
            }
            getchar();
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(G[i][j]=='.')
                {
                    dfs(i,j,0);
                }
            }
        }
        cout<<ans<<endl;
        ans=0;
        memset(G,0,sizeof(G));
    }


    return 0;
}
