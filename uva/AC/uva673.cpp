#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
    stack<char> tex;
    int n;

    cin>>n;
    getchar();
    while(n--)
    {
        char temp;
        while(scanf("%c",&temp)&&temp!='\n')
        {
            if(tex.empty())tex.push(temp);

            else  if(tex.top()=='[' && temp==']'||tex.top()=='('&&temp==')')
            {
                    tex.pop();
            }
            else
                tex.push(temp);
        }
        if(tex.empty())cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

        while(!tex.empty())tex.pop();
    }


    return 0;
}
