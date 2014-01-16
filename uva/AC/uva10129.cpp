#include <iostream>
#include <string.h>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxn = 30;
char words[10000];
int G[maxn][maxn];
int vis[maxn];
int in[maxn];
int out[maxn];
bool judge=false;

void dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<26;i++)
    {
        if(G[u][i] &&!vis[i])
        {
            dfs(i);
        }
    }
}
bool DFS()
{
    int cnt=0;
    for(int i=0;i<26;i++)
    {
        if( (in[i] ||out[i]) && !vis[i])
        {
            dfs(i);
            cnt++;
        }
    }
    if(cnt>1)
    {
        return false;
    }
    else
        return true;
}
bool euler()
{
    int n1=0,n2=0;
    for(int i=0;i<26;i++)
    {
        if(in[i]-out[i]==1)
        {
            n1++;
            if(n1>1)return false;
        }
        if(out[i]-in[i]==1)
        {
            n2++;
            if(n2>1)return false;
        }
        if(abs(out[i]-in[i])>1)
            return false;
    }
    return true;
}


int main()
{
    int tst;
    cin>>tst;
    while(tst--)
    {
        int Nw;
        cin>>Nw;
        cin.ignore();
        memset(words,'\0',sizeof(words));
        for(int i=0;i<Nw;i++)
        {
            gets(words);
            int last = words[strlen(words)-1]-'a';
            int first = words[0]-'a';
            G[first][last]++; G[last][first]++;
            in[first]++;out[last]++;
        }
        if( ! DFS())
        {
            cout<<"The door cannot be opened."<<endl;
        }
        else
        {
            if(!euler())
            {
                cout<<"The door cannot be opened."<<endl;
            }
            else
            {
                cout<<"Ordering is possible."<<endl;
            }
        }
        memset(out,0,sizeof(out));
        memset(in,0,sizeof(in));
        memset(G,0,sizeof(G));
        memset(vis,0,sizeof(vis));
    }

    return 0;
}
