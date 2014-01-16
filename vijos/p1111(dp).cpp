#include <iostream>
#include <memory.h>
using namespace std;

int lcs[200][200];

int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {

        for(int i=0;i<s1.length();i++)
        {
            for(int j=0;j<s2.length();j++)
            {
                if(  s1[i] == s2[j])lcs[i+1][j+1] = lcs[i][j]+1;
                else
                    lcs[i+1][j+1] = max ( lcs[i][j+1], lcs[i+1][j]);
            }
        }
        cout<<s1.length()+s2.length() - lcs[s1.length()][s2.length()]<<endl;
        memset(lcs,0,sizeof(lcs));
    }


    return 0;
}
