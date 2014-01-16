#include <iostream>
#include <cmath>
using  namespace std;
const int maxn = 60;
int brack[maxn];
int main()
{
    int N,tst=1;
    while(cin>>N)
    {
        if(N==0)
        {
            break;

        }

        int sum=0;
        for(int i=0;i<N;i++)
        {
            cin>>brack[i];
            sum+=brack[i];
        }
        sum/=N;

        int ans=0;
        int leave=0;
        for(int i=0;i<N;i++)
        {

            if(brack[i]>sum)
            {
                ans+=brack[i]-sum;
                leave+=brack[i]-sum;
            }
            else if(brack[i]<sum)
            {
                if(leave + brack[i]>=sum)
                {
                    leave = leave - (sum-brack[i]);
                }
                else
                {
                    leave = leave - (sum-brack[i]);
                }
            }

        }
        cout<<"Set #"<<tst++<<endl;
        cout<<"The minimum number of moves is "<<ans<<"."<<endl<<endl;

    }


    return 0;
}
