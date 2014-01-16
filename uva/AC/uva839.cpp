#include <iostream>
#include <cstdio>
using namespace std;


int flag=true;
int solve()
{

    int WL,DL,WR,DR;
    cin>>WL>>DL>>WR>>DR;
    if(WL==0)WL=solve();
    if(WR==0)WR=solve();
    if(flag && WL*DL == WR*DR)
    {
        return WL+WR;
    }
    else
    {
        flag=false;
        return 0;
    }

}


int main()
{

    int tst;
    cin>>tst;
    while(tst--)
    {
        int WL,DL,WR,DR;
        cin>>WL>>DL>>WR>>DR;
        if(WL==0)WL=solve();
        if(WR==0)WR=solve();
        if(flag && WL*DL == WR*DR)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

        flag =true;
        if(tst)
            putchar(10);
    }


    return 0;
}
