#include <iostream>
using namespace std;

int N,H;

int main()
{
    int tst;
    cin>>tst;
    while(tst--)
    {
        cin>>N>>H;

        int org=0;
        for(int i=1;i<1<<N;i++)
        {
            int cnt=0;
            for(int j=0;j<N;j++)
            {
                if(i& 1<<j)
                {
                    cnt++;
                }
            }
            if(cnt==H)
            {
                for(int k=N-1;k>=0;k--)
                {
                    if(i & 1<<k )cout<<"1";
                    else cout<<"0";
                }
                cout<<endl;
                cnt=0;
                org=i;
            }
        }
        if(tst)
        cout<<endl;

    }

    return 0;
}
