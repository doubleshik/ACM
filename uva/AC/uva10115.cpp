#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

const int maxn=300;

char org[12][maxn];
char rep[12][maxn];
char str[maxn];



int main()
{
   // freopen("autoedit.in","r",stdin);
    //freopen("autoedit.out","w",stdout);

    int rule;
    while(cin>>rule)
    {
        if(rule==0)
            break;

        getchar();
        for(int i=0;i<rule;i++)
        {
            gets(org[i]);
            gets(rep[i]);
        }
        gets(str);

        for(int i=0;i<rule;i++)
        {
            char* p=strstr(str,org[i]) ;
            int input;
            while(p)
            {
                char buf[maxn];
                int olen=strlen(org[i]);
                int rlen = strlen(rep[i]);
                strcpy(buf,p+olen);
                strcpy(p,rep[i]);
                strcpy(p+rlen,buf);
                p=strstr(str,org[i]);
                memset(buf,' ',sizeof(buf));

            }

        }
        cout<<str<<endl;
    }



    return 0;
}
