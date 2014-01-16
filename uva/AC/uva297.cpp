#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
const int maxn = 4096;
char tree1[maxn];
char tree2[maxn];
char newtree[maxn];
int pn=0;
int x=0;
int cal(int ans,int mul)
{
  //  cout<<x<<" "<<ans<<" "<<mul<<endl;

    if(x>=strlen(newtree))return 0;
    if(newtree[x]=='e')
        return 0;
    if(newtree[x] == 'f')
        return mul;
    if(newtree[x]=='p')
    {
        for(int i=1;i<=4;i++)
        {
            x++;
          // cout<<"before"<<"i "<<i<<"x:  "<<x<<"ans  "<<ans<<endl;
            ans+=cal(0,mul/4);
         //  cout<<"i "<<i<<"x:  "<<x<<"ans  "<<ans<<endl;
        }
      //  cout<<"return "<<endl;
       return ans;
    }

    return 0;
}
void solve()
{
    int p1=0,p2=0;
    while(p1<strlen(tree1)&&p2<strlen(tree2))
    {
        if(p1==strlen(tree1) || p2==strlen(tree2))break;
       // cout<<p1<<" "<<p2<<endl;
        if(tree1[p1]=='p' && tree2[p2]=='p')
        {

            newtree[pn++]='p';
            p1++;p2++;
        }
        else if(tree1[p1]=='f')
        {

            newtree[pn++]='f';
            if(tree2[p2]=='p')p2+=5;
            else p2++;
            p1++;
        }
        else if(tree2[p2]=='f')
        {

            newtree[pn++]='f';
            if(tree1[p1]=='p')p1+=5;
            else p1++;
            p2++;
        }
        else if(tree1[p1]=='e'&&tree2[p2]=='e')
        {
             // cout<<"here2"<<endl;
            newtree[pn++]='e';
            p1++;p2++;
        }
        else if(tree1[p1]=='p'&&tree2[p2]=='e')
        {
          // cout<<"here3"<<endl;
            for(int i=0;i<=4;i++)
                newtree[pn++]=tree1[p1+i];
            p1+=5;
            p2++;
        }
        else if(tree2[p2]=='p'&&tree1[p1]=='e')
        {
           // cout<<"here4"<<endl;
               for(int i=0;i<=4;i++)
                newtree[pn++]=tree2[p2+i];
            p1++;
            p2+=5;
        }

       // cout<<newtree<<endl;
    }
     for(int i=p1+1;i<strlen(tree1)-1;i++)
        newtree[pn++]=tree1[i];
    for(int i=p2+1;i<strlen(tree2)-1;i++)
        newtree[pn++]=tree2[i];
   // cout<<newtree<<endl;
}

int main()
{
    int tst;
    cin>>tst;
    getchar();
    int finalans=0;
    while(tst--)
    {
        gets(tree1);
        gets(tree2);

        solve();
       // cout<<newtree<<strlen(newtree)<<endl;

        finalans=cal(0,64*16);
        cout<<"There are "<<finalans<<" black pixels."<<endl;
        pn=0;
        memset(tree1,'\0',sizeof(tree1));
        memset(tree2,'\0',sizeof(tree2));
        memset(newtree,'\0',sizeof(newtree));
        x=0;
        finalans=0;
    }

    return 0;
}
