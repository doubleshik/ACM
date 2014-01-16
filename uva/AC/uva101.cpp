#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <cstdio>
using namespace std;

int blocks[30][30];
int height[30];
int bheight[30];
int pos[30];
int num;

int comprehend(char* cmd)
{
    if(strstr(cmd,"move"))
    {
        if(strstr(cmd,"onto"))return 1;
        else if(strstr(cmd,"over"))return 2;
    }
    else
    {
        if(strstr(cmd,"onto")) return 3;
        else return 4;
    }

}

void run(char* cmd)
{
    int cmdkind = comprehend(cmd);
    int from,to;
    char rub[100];
    if(cmdkind==1)
    {
        sscanf(cmd,"%s %d %s %d",rub,&from,rub,&to);



        int px = pos[from];
        int py = height[from];
        int ptx = pos[to];
        int pty = height[to];
         if(from==to||px==ptx)return;
        for(int i= py+1;i<=bheight[px];i++)
        {
            int now = blocks[px][i];
            blocks[now][0]=now;
            bheight[now]=0;
            pos[now] = now;
            height[now]=0;
        }
        bheight[px]=py;



        for(int i=pty+1;i<=bheight[ptx];i++)
        {
            int now = blocks[ptx][i];
            blocks[now][0]=now;
            bheight[now]=0;

            pos[now] = now;
            height[now]=0;
        }

       // cout<<"px"<<px<<"py"<<py<<"ptx"<<ptx<<"pty"<<pty<<endl;
        bheight[ptx]=pty+1;
        blocks[ptx][pty+1] = from;

        bheight[px]--;
        pos[from]=ptx;
        height[from]=pty+1;

    }
    if(cmdkind==2)
    {
        sscanf(cmd,"%s %d %s %d",rub,&from,rub,&to);


        int px = pos[from];
        int py = height[from];
        int ptx = pos[to];
        int pty = bheight[ptx];
         if(from==to||px==ptx)return ;
        for(int i= py+1;i<=bheight[px];i++)
        {
            int now = blocks[px][i];
            blocks[now][0]=now;
            bheight[now]=0;
            pos[now] = now;
            height[now]=0;
        }
        bheight[px]=py;



        //cout<<"px"<<px<<"py"<<py<<"ptx"<<ptx<<"pty"<<pty<<endl;
        bheight[ptx]=pty+1;
        blocks[ptx][pty+1] = from;

        bheight[px]--;
        pos[from]=ptx;
        height[from]=pty+1;



    }

    if(cmdkind==3)
    {
        sscanf(cmd,"%s %d %s %d",rub,&from,rub,&to);

        int px = pos[from];
        int py = height[from];


        int ptx = pos[to];
        int pty = height[to];

        if(from==to||px==ptx)return;

        for(int i=pty+1;i<=bheight[ptx];i++)
        {
            int now = blocks[ptx][i];
            blocks[now][0]=now;
            bheight[now]=0;

            pos[now] = now;
            height[now]=0;
        }
        bheight[ptx] = pty;

        for(int i=py;i<=bheight[px];i++)
        {
            int now = blocks[px][i];
            blocks[ptx][++pty] = now;
            pos[now] = ptx;
            height[now] = pty;
        }
        bheight[px] = py-1;

       // cout<<"px"<<px<<"py"<<py<<"ptx"<<ptx<<"pty"<<pty<<endl;
        bheight[ptx]=pty;
    }



    if(cmdkind==4)
    {
        sscanf(cmd,"%s %d %s %d",rub,&from,rub,&to);


        int px = pos[from];
        int py = height[from];
         int ptx = pos[to];
        int pty = bheight[ptx];
          if(from==to||px==ptx)return ;
        for(int i= py;i<=bheight[px];i++)
        {
            int now = blocks[px][i];
            blocks[ptx][++pty]=now;
            pos[now] = ptx;
            height[now]=pty;
        }
        bheight[px]=py-1;

       // cout<<"px"<<px<<"py"<<py<<"ptx"<<ptx<<"pty"<<pty<<endl;
        bheight[ptx]=pty;
    }

}
void print()
{
    for(int i=0;i<num;i++)
    {
        printf("%d:",i);
        for(int j=0;j<=bheight[i];j++)
        {
            printf(" %d",blocks[i][j]);
        }
        printf("\n");
    }

}


int main()
{
    cin>>num;

    char cmd[100];

    memset(height,0,sizeof(height));
    for(int i=0;i<num;i++)
    {
        blocks[i][0]=i;
        bheight[i]=0;
        height[i]=0;
        pos[i]=i;
    }


    getchar();
   // print();
    while(gets(cmd) && !strstr(cmd,"quit"))
    {
        run(cmd);

    }
       print();

    return 0;
}
