
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
using namespace std;
const int sp = -2147483645;
int row,col;
int ans[2000][2000];
vector < vector<string> > v;

int dfs(int u,int w)
{
    if(ans[u][w]!=sp) return ans[u][w];

    if( v[u][w][0] !='=')
        return ans[u][w] = atoi(v[u][w].cstr());

    else

    {



    }

}

int main()
{
    int tst;
    cin>>tst;
    while(tst--)
    {
        cin>>row>>col;
        for(int i=0;i<row;i++)
        {
            vector<string> x;
            for(int j=0;j<col;j++)
            {
                string tmp;
                cin>>tmp; x.push_back(tmp);
            }
            v.push_back(x);
        }


       for(int i=0;i<v.size();i++)
       {
        for(int j=0;j<v[i].size();j++)
        {
            dfs(i,j);
        }
       }


    }


    return 0;
}
