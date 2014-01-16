#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
double K[1000000];
double X[1000];
double Y[1000];
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    char tmp[10];
    cin>>n;
    cin.get();
    cin.get();
    while(n--)
    {
        int p=0;
       // getchar();
        while(gets(tmp))
        {
            //cout<<"tmp"<<tmp<<endl;
            if(!tmp[0])break;
            sscanf(tmp,"%lf %lf",&X[p],&Y[p]);
           // cout<<"X Y "<<X[p]<<" "<<Y[p]<<endl;
            p++;
        }
        int pk=0,ans=2;
        for(int i=0;i<p;i++)
        {
            pk=0;
            for(int j=0;j<p;j++)
            {
                if(i==j)continue;
                //cout<<Y[j]<<" "<<Y[i]<<" "<<X[j]<<" "<<X[i]<<endl;
                K[pk++] = (Y[j]-Y[i])/(X[j]-X[i]);
                //cout<<K[pk-1]<<endl;
            }
            sort(K,K+pk);
        //cout<<"ok"<<endl;
            int tans=2;
            for(int i=0;i<pk-1;i++)
            {
                int j=i,m=j+1;
                tans=2;
                while(K[j]==K[m])
                {
                    tans++;j++;m++;
                }
                if(tans>ans)ans=tans;
            }
        }
        cout<<ans<<endl;
        if(n)cout<<endl;
    }
    return 0;
}
