#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <memory.h>
using namespace std;

const int maxn = 300;
char tree[30][maxn];


int dfs(int left,int right,int n)
{
    for(int i=left;i<right;i++)
    {
        if(tree[n][i]!=' ' &&tree[n][i]!='\0')
        {
            if(tree[n+1][i]!='|'){cout<<tree[n][i]<<"()";}
            else
            {
                int up=i,down=i;
                while(tree[n+2][up]=='-')up--;
                while(tree[n+2][down]=='-')down++;
                cout<<tree[n][i];
                cout<<"(";
                dfs(up+1,down,n+3);
                cout<<")";
            }
        }
    }
    return 0;


}


int main()
{

    freopen("in.txt","r",stdin);
    int tst;
    cin>>tst;
    getchar();
    while(tst--)
    {
        int p=0;
        while(gets(tree[p++]))
        {
            if(tree[p-1][0]=='#')break;
        }
        if(p-1==0)
        {
            cout<<"()"<<endl;
        }
        else
        {
            cout<<"(";
            dfs(0,maxn,0);
            cout<<")"<<endl;
        }
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
