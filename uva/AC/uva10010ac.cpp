#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 60;


int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
char dict[maxn][maxn];
char key[maxn];
int main()
{
    int test=0;

    cin>>test;
    while(test--)
    {
        int row,line;
        cin>>row>>line;
        for(int i=1;i<=row;i++)
            for(int j=1;j<=line;j++)
            {
                cin>>dict[i][j];
                dict[i][j]=tolower(dict[i][j]);
            }
        int keyword;
        cin>>keyword;
        int found=0;

        for(int kk=0;kk<keyword;kk++)
        {
            scanf("%s",key);
            for(int i=0;i<strlen(key);i++)
                key[i]=tolower(key[i]);
            for(int i=1;i<=row;i++)
            {
                for(int j=1;j<=line;j++)
                {
                    if(dict[i][j]!=key[0])
                        continue;
                        for(int q=0;q<8;q++)
                        {
                            int mx=dx[q],my=dy[q],tk=0,tj=j,ti=i;
                            //cout<<"before"<<i<<" "<<j<<endl;
                            while(ti>=1&&ti<=row && tj>=1&&tj<=line&&tk<strlen(key))
                            {
                                if(dict[ti][tj]!=key[tk]){
                                    break;
                                }
                                //cout<<"mx my"<<" "<<mx<<" "<<my<<endl;
                                //cout<<"ti tj"<<" "<<ti<<" "<<tj<<endl;
                                ti+=mx;
                                tj+=my;
                                tk++;
                               // cout<<ti<<" "<<tj<<"dir"<<mx<<" "<<my<<"tk"<<tk<<"      "<<dict[ti][tj]<<" "<<key[tk]<<endl;

                            }
                            if(tk==strlen(key))
                            {
                                cout<<i<<" "<<j<<endl;
                                found=1;
                                break;
                            }
                            tk=0;
                    }
                    if(found)break;
                }
                if(found)break;
            }
        found=0;
        }
        if(test!=0)
            cout<<endl;
    }



    return 0;
}
