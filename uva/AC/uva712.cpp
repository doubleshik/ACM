#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

 int level ;
string temp;
char leaves[1000];
char que[1000];
char ans[1000];
int ansp=0;
int tst=0;
int minu=1;
int main()
{

    while(scanf("%d",&level) &&level !=0)
    {
        tst++;
        getchar();
        getline(cin,temp);
        scanf("%s",leaves);

        minu=1;
        for(int i=0;i<level;i++)
            minu*=2;


        int query ;
        cin>>query;
        for(int k=0;k<query;k++)
        {
//            memset(ans,'\0',sizeof(ans));
//            memset(que,'\0',sizeof(que));
            scanf("%s",que);
            int pos=0;
            for(int i=0;i<level;i++)
            {
                if(que[i]=='0')
                {
                    pos=pos*2+1;
                }
                else
                {
                    pos=pos*2+2;
                }
            }
            ans[ansp++]=leaves[pos-minu+1];
            pos=0;
        }
        cout<<"S-Tree #"<<tst<<":"<<endl;
        for(int i=0;i<query;i++)printf("%c",ans[i]);
        cout<<endl;
        cout<<endl;
        ansp=0;
    }


    return 0;
}
