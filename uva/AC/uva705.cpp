#include<stdio.h>
#include<string.h>
int num=0,f,sum,max,pos,h,w,move[4][2]={1,0,-1,0,0,-1,0,1},map[400][400];
void dfs(int x,int y)
{int X,Y,i;
 for (i=0;i<4;i++)
 {X=x+move[i][0];
  Y=y+move[i][1];
  if ((X>=0)&&(X<h*3)&&(Y>=0)&&(Y<w*3))
  {if (map[X][Y]==0)
   {++pos; map[X][Y]=1; dfs(X,Y);}
  }
  else
  f=0;;
 }
};
int main()
{int i,j;
 char s[200];
 while (scanf("%d%d",&w,&h),w+h)
 {getchar();
  ++num; sum=0; max=0;
  for (i=0;i<h*3;i++)
  for (j=0;j<w*3;j++)
  map[i][j]=0;
  for (i=0;i<h;i++)
  {gets(s);
   for (j=0;j<w;j++)
   if (s[j]=='\\')
        {map[3*i][3*j]=1;map[3*i+1][3*j+1]=1;map[3*i+2][3*j+2]=1;}
   else {map[3*i+2][3*j]=1;map[3*i+1][3*j+1]=1;map[3*i][3*j+2]=1;}

  }

 for (i=0;i<3*h;i++)
 for (j=0;j<3*w;j++)
 {if (map[i][j]==0)
  {pos=1; f=1; map[i][j]=1;
   dfs(i,j);
   if (f)
   {++sum;
    if (pos>max) max=pos;
   }
  }
 }
 if (sum==0) printf("Maze #%d:\nThere are no cycles.\n\n",num);
 else printf("Maze #%d:\n%d Cycles; the longest has length %d.\n\n",num,sum,max/3);

 }
 return 0;
}
