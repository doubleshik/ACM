#include <iostream>
#include <vector>
#include <string>
using namespace std;

string v;
vector < string > dict;
int p,k,s;

int main()
{

    cin>>p>>k;
    cin.ignore();
    string tmp;
    for(int i=0;i<p;i++)
    {
        cin>>tmp;
        v.append(tmp);
    }
    cin>>s;
    cin.ignore();
    for(int i=0;i<s;i++)
    {
        cin>>tmp;
        dict.push_back(tmp);
    }











    return 0;
}
