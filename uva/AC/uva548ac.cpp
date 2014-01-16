#include <iostream>
#include <string>
#include <sstream>
#include <limits.h>
#include <malloc.h>
#include <cstdio>
#include <string.h>
using namespace std;

const int maxn = 50000;

typedef struct Tnode
{
    int data;
    struct Tnode* left,*right;
}Node;

int inorder[maxn];
int postorder[maxn];
int pi,pp;

int num = 0;

Node* newnode()
{
    Node* T;
    T=(Node*)malloc(sizeof(Node));
    if(!T)return NULL;
    T->left=NULL;T->right=NULL;
    T->data=0;
    return T;
}


Node* build(int left,int right,int* inorder)
{
    //cout<<"LEfT : "<<left<<"RIGHT : "<<right<<endl;

    //cout<<"POST :"<<pp<<"  "<<postorder[pp]<<" NExt"<<pp-1<<" "<<postorder[pp-1]<<endl;
    //cout<<endl;


    if(left>right||left<0 || right>=pi)return NULL;
    if(left==right)
    {
        //cout<<"here1"<<endl;
        Node* now;
        now = newnode();
        now->data=inorder[left];
        now->left=now->right=NULL;
        pp--;
        return now;
    }


    for(int i=left;i<=right;i++)
    {
        if(inorder[i]==postorder[pp-1])
        {
            //cout<<"here2"<<endl;
            Node* now;
            now = newnode();now->data= inorder[i];
            pp--;
            now->left = build(i+1,right,inorder);
           // if(!now->left)pp--;
            now->right = build (left,i-1,inorder);
            return now;
        }
    }

}
void print(Node* T)
{
    if(T)
    {
        cout<<T->data<<" ";
        print(T->left);
        print(T->right);
    }
}
int MIN,LAST,ans;
void cal(int sum,Node* T)
{
    if(T==NULL)return;
    sum+=T->data;
    if(T->left==NULL && T->right==NULL)
    {
        if(sum<MIN)
        {
            MIN=sum;
            LAST= T->data;
            ans=LAST;
        }
        if(sum==MIN && T->data<LAST)
        {
            LAST=T->data;
            ans=LAST;
        }
    }
    else
    {
        if(T->left)
            cal(sum,T->left);
        if(T->right)
            cal(sum,T->right);
    }

}


void del(Node* T)
{
    if(T)
    {
        del(T->left);
        del(T->right);
        free(T);
    }
}
Node* root;
int main()
{
    int ti;
    char tc;
    while(scanf("%d%c",&ti,&tc)!=EOF)
    {
        inorder[pi++]=ti;
        while(tc!='\n')
        {
            scanf("%d%c",&ti,&tc);
            inorder[pi++]=ti;
        }
        scanf("%d%c",&ti,&tc);
        postorder[pp++]=ti;
        while(tc!='\n')
        {
            scanf("%d%c",&ti,&tc);
            postorder[pp++]=ti;
        }

        root=build(0,pi-1,inorder);
       // print(root);
       // cout<<endl;
        MIN = INT_MAX;
        LAST = 0;
        ans=0;
        cal(0,root);
        cout<<ans<<endl;
        del(root);
        pi=0;pp=0;
        memset(inorder,0,sizeof(inorder));
        memset(postorder,0,sizeof(postorder));
        //print();
    }
    //del(root);
    return 0;
}
