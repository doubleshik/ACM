#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define REP(i,N) for(int i=0;i<N;i++)
int G[9][9];
int row[9][9];
int line[9][9];
int sq[9][9][9];
int flag = false;
int dfs(int cnt)
{
    cout<<cnt<<endl;
    if(cnt==81)
    {
        flag =true;
        return 0;
    }


    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            int dd=0;
            if(G[i][j] == 0)
            for(int k=1;k<=9;k++)
            {
                if((!row[i][k])&&(!line[j][k])&&(!sq[i/3][j/3][k]) )
                {
                    dd=1;
                    G[i][j] =k;
                    row[i][k]=1;
                    line[j][k]=1;
                    sq[i/3][j/3][k]=1;

                    dfs(cnt+1);
                    if(flag )return 0;

                    G[i][j] =0;
                    row[i][k]=0;
                    line[j][k]=0;
                    sq[i/3][j/3][k]=0;

                }
            }

        }
    }

    return 0;
}


int main()
{

    freopen("IN","r",stdin);
    int tst;
    cin>>tst;
    cin.ignore();
   // cout<<tst<<endl;
    while(tst--)
    {
        char c;
        int cc=0;
        REP(i,9)
        {
            REP(j,9)
            {
                scanf("%c",&c);
                G[i][j]=c-'0';
                if(G[i][j])
                {
                    //cout<<G[i][j]<<endl;
                    row[i][G[i][j]]=1;
                    line[j][G[i][j]]=1;
                    sq[i/3][j/3][G[i][j]]=1;
                    cc++;
                }
            }
            getchar();

        }

        //cout<<cc<<endl;
//        REP(i,9)
//
//        {
//            REP(j,9)
//             {   cout<<G[i][j]<<' ';}
//            cout<<endl;
//
//        }


        REP(i,9)
        {
            REP(j,9)
            {
          //      cout<<G[i][j];
                if(G[i][j]==0)
                {
                    //cout<<"here";
                    for(int k=1;k<=9;k++)
                    {
                        if((!row[i][k])&&(!line[j][k])&&(!sq[i/3][j/3][k]) )
                        {

                            G[i][j] = k;
                            row[i][k]=1;
                            line[j][k]=1;
                            sq[i/3][j/3][k]=1;

                            dfs(cc+1);

                            if(flag) break;

                            G[i][j] = 0;
                            row[i][k]=0;
                            line[j][k]=0;
                            sq[i/3][j/3][k]=0;
                        }
                    }
                }
                if(flag)break;
            }
            if(flag)break;
        }

        if(flag)
        {
            REP(i,9)
            {
                REP(j,9)
                {
                    cout<<G[i][j];
                }
                cout<<endl;
            }

        }


        memset(G,0,sizeof(G));

        memset(row,0,sizeof(row));

        memset(line,0,sizeof(line));

        memset(sq,0,sizeof(sq));

        flag = false;

    }



    return 0;
}
