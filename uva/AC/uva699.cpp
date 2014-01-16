#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <memory.h>
using namespace std;

const int maxn = 1000;
int tree[maxn];
int tst=1;
int n=500;int tmp;
bool input()
{
    scanf("%d",&tmp);
    if(tmp!=-1)
    {
        tree[n]+=tmp;
        n--;
        input();
        n+=2;
        input();
        n--;
        return true;
    }
    else
        return false;
}
void print()
{
    int i=0;
    while(tree[i]==0)i++;
    cout<<"Case "<<tst++<<":"<<endl;
    for(;i<maxn;i++)
    {
        if(tree[i+1]==0)break;
        cout<<tree[i]<<" ";
    }
    cout<<tree[i]<<endl;
    cout<<endl;

    memset(tree,0,sizeof(tree));

}

int main()
{
    memset(tree,0,sizeof(tree));

    while(input())
        print();
    return 0;
}
