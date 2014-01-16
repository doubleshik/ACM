/*
ID:doubles3
PROB:transform
LANG:C++
*/

#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

char org[30][30];
char after[30][30];
int N;

FILE* fin = fopen("transform.in","r");
FILE* fout= fopen("transform.out","w");
int solve(int roate,char orgx[30][30],char afterx[30][30])
{
   int flag=1;
   if(roate == 90)
   {
       flag=1;
       for(int i=1;i<=N;i++)
       {
           for(int j=1;j<=N;j++)
           {
               if(orgx[i][j] != afterx[j][N-i+1]  )
               {
                   flag=0;
                   break;
               }
           }
           if(flag==0)return 0;
       }
        if(flag==1)
        {
           // fprintf(fout,"1\n");
            return 1;
        }
   }

   if(roate==180)
   {
       flag=1;
       for(int i=1;i<=N;i++)
       {
            for(int j=1;j<=N;j++)
            {
                if(orgx[i][j] !=  afterx [N-i+1][N-j+1])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)
            {
                return 0;
            }
       }
       if(flag==1)
       {
        //   fprintf(fout,"2\n");
           return 1;
       }
   }



 if(roate==270)
   {
       flag=1;
       for(int i=1;i<=N;i++)
       {
            for(int j=1;j<=N;j++)
            {
                if(orgx[i][j] !=  afterx [N-j+1][i])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)
            {
                return 0;
            }
       }
       if(flag==1)
       {
           //fprintf(fout,"3\n");
           return 1;
       }
   }


}

int reflection()
{
    int flag=1;
       for(int i=1;i<=N;i++)
       {
            for(int j=1;j<=N;j++)
            {
                if(org[i][j] !=  after [i][N-j+1])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)
            {
                return 0;
            }
       }
       if(flag==1)
       {
           fprintf(fout,"4\n");
           return 1;
       }
}

int comb()
{
    char temp [30][30];
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            temp[i][j]=org[i][N-j+1];
    int ans=0;


    ans=solve(90,temp,after);
    if(ans) {fprintf(fout,"5\n");return 1;}
    ans = solve(180,temp,after);
    if(ans){fprintf(fout,"5\n");return 1;}
    ans =solve(270,temp,after);
    if(ans){fprintf(fout,"5\n");return 1;}

    return 0;

}
int orgin()
{
    int flag=1;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
    {
        if (org[i][j]!=after[i][j])
        {
            flag=0;
            break;
        }
    }

    if(flag){fprintf(fout,"6\n");return 1;}
    else return 0;
}
int main()
{
    char _temp;
    fscanf(fin,"%d",&N);
    fscanf(fin,"%c",&_temp);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            fscanf(fin,"%c",&org[i][j]);
        }
        fscanf(fin,"%c",&_temp);
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
           fscanf(fin,"%c",&after[i][j]);
        }
        fscanf(fin,"%c",&_temp);
    }

    int ans=0;
    ans=solve(90,org,after);
    if(!ans) ans = solve(180,org,after);else {fprintf(fout,"1\n");return 0;}
    if(!ans) ans =solve(270,org,after);else {fprintf(fout,"2\n");return 0;}
    if(!ans) ans = reflection();else  {fprintf(fout,"3\n");return 0;}

    if(!ans) ans = comb();else return 0;
    if(!ans) ans = orgin();else return 0;
    if(!ans) fprintf(fout,"7\n");
    fclose(fin);
    fclose(fout);
    return 0;

}
