#include <iostream>
#include <algorithm>
using namespace std;

char opera[]={'*','+','-'};
int arr[6];
bool flag=false;
void dfs(int v,int cur,int u)
{
    if(cur>5)
    {
        if(v==23 && !flag)
        {
            flag=true;
            cout<<"Possible"<<endl;
        }
        return ;
    }

   dfs(v+arr[u],cur+1,u+1);
   dfs(v-arr[u],cur+1,u+1);
   dfs(v*arr[u],cur+1,u+1);

}


int main()
{
    while(1)
    {
        for(int i=0;i<5;i++)
        {
            cin>>arr[i];
        }
        if(arr[0]==0 && arr[1]==0&&arr[2]==0&&arr[3]==0&&arr[4]==0)
        {
            break;
        }
        sort(arr,arr+5);
        do
        {
                dfs(arr[0],1,1);

                if(flag)break;
        }while(next_permutation(arr,arr+5));
        if(!flag )
            cout<<"Impossible"<<endl;

        flag=false;
    }

    return 0;
}
