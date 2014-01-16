#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct So{

    int teach,job;
    bool operator < (const So& x) const{
        return job>x.job;
    }
};


int main()
{
    int num;
    vector<So> v;
    So temp;
    int tst=0;
    while(cin>>num && num)
    {
        v.clear();
        for(int i=0;i<num;i++)
        {
            cin>>temp.teach>>temp.job;
            v.push_back(temp);
        }
        sort(v.begin(),v.end());

        cout<<"Case "<<++tst<<": ";

        int ans=0,start=0;
        for(int i=0;i<num;i++)
        {
            start+=v[i].teach;
            if(ans< (v[i].job+start))ans=v[i].job+start;
        }
        cout<<ans<<endl;
    }

}
