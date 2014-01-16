#include <iostream>
using namespace std;
int X[200];
int Y[200];
int main()
{
    int N;
    while(cin>>N &&N!=0)
    {
        for(int i=0;i<2*N;i++)
        {
            cin>>X[i]>>Y[i];
        }

        for(int A=-500;A<=500;A++)
        {
            int neg=0,pos=0,zero=0,flag=0;
            for(int B=-500;B<=500;B++)
            {
                if(A==0&&B==0)continue;
                for(int i=0;i<2*N;i++)
                {
                    if(A*X[i]+B*Y[i]>0)pos++;
                    if(A*X[i]+B*Y[i]<0)neg++;
                    if(A*X[i]+B*Y[i]==0){zero++;break;}
                }
               // cout<<"POS"<<pos<<" NEG"<<neg<<"zeor"<<zero<<endl;
                if(pos==neg && zero==0)
                {
                    cout<<A<<" "<<B<<endl;flag=1;
                    break;
                }
                pos=neg=zero=0;
            }
            if(flag)break;
        }

    }


    return 0;
}
