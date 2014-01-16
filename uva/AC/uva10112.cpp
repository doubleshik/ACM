#include <iostream>
#include <math.h>
using namespace std;
const int maxn =30;
char P[maxn];
int x[maxn];
int y[maxn];
int N;

double area(double ax,double ay,double bx,double by,double cx,double cy)
{
    //0.5 ¡Á [(y3 - y1)(x2 - x1) - (y2 - y1)(x3 - x1)].
    double ans ;
    ans = 0.5 * ((cy-ay)*(bx-ax)-(by-ay)*(cx-ax));
    ans = ans<0?-ans:ans;
    return ans;
}
bool check(int o,int a,int b,int c,double  abc)
{
    double x1 = area(x[o],y[o],x[a],y[a],x[b],y[b]);
    double x2 = area(x[o],y[o],x[a],y[a],x[c],y[c]);
    double x3 = area(x[o],y[o],x[b],y[b],x[c],y[c]);
    if(  fabs(abc-x1-x2-x3)<1e-9 )return true;              //ÔÚÔ²ÄÚ
    else return false;
}

int ansa,ansb,ansc,ansmax;
void solve()
{
    ansmax=0;
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            for(int k=j+1;k<N;k++)
            {
                int flag=1;
                double s =  area(x[i],y[i],x[j],y[j],x[k],y[k]);

                for(int m =0;m<N;m++)
                {
                    if(m==i||m==j||m==k)continue;
                //    cout<<i<<" "<<j<<" "<<k<<endl;
                    if(check(m,i,j,k,s))
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                {
                    if(s>ansmax)
                    {
                        ansa = i; ansb=j;ansc=k;
                        ansmax =s;
                   //     cout<<ansa<<" "<<ansb<<" "<<ansc<<endl;
                    }
                }
                else
                    flag=1;
            }
        }
    }
}



int main()
{

    while(cin>>N && N)
    {
        ansa=ansb=ansc=ansmax=0;
        for(int i=0;i<N;i++)
        {
            cin>>P[i];
            cin>>x[i]>>y[i];
        }
        solve();
        //cout<<ansa<<ansb<<ansc<<endl;
        cout<<P[ansa]<<P[ansb]<<P[ansc]<<endl;
    }



    return 0;
}
