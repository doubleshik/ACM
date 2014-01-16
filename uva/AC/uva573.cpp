#include <iostream>
using namespace std;


int main()
{
    double H,U,D,F;
    while(cin>>H>>U>>D>>F, H!=0)
    {
        double delta = U*F*0.01,height=0,cnt=1;
        while(1)
        {
            if(U>0)
            {
                height += U;
            }
            if(height>H)
            {cout<<"success on day "<<cnt<<endl;break;}
            U-=delta;
            height-=D;
            if(height<0)
            {cout<<"failure on day "<<cnt<<endl;break;}


            cnt++;
        }
    }

    return 0;
}
