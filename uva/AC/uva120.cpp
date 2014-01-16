#include <iostream>
#include <string>
#include <iterator>
#include <deque>
#include <sstream>
#include <deque>
#include <algorithm>
using namespace std;


int main()
{
    for(string strline; getline(cin,strline);cout<<'0'<<endl)
    {

        cout<<strline<<endl;
        istringstream iss(strline);
        deque<int> Stack;
        for(int nDiam;iss>>nDiam;Stack.push_front(nDiam));

        for(deque<int>::iterator i = Stack.begin();i!=Stack.end();++i)
        {
            deque<int>::iterator iMax = max_element (i,Stack.end());
            if(iMax !=i)
            {
                if(iMax != Stack.end()-1)
                {
                    reverse (iMax,Stack.end());
                    cout<<distance(Stack.begin(),iMax)+1<<" ";
                }
                reverse (i,Stack.end());
                cout<<distance(Stack.begin(),i)+1<<" ";
            }
        }
    }
    return 0;
}
