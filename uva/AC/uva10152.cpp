#include <iostream>
#include <string>
#include <queue>
#include <string.h>
#include <cstdio>
using namespace std;

deque<string> org;
deque<string> after;

int num;
void que()
{
   int po=0,pa=0;
   string temp;
   while(po<num)
   {
       if(org[po]==after[pa])
       {
           po++;pa++;
       }
       else
        po++;
   }
   for(int i=pa;i<num;i++)
   {
       cout<<after[i]<<endl;
   }

}


int main()
{

    int tst;
    cin>>tst;
    while(tst--)
    {

        cin>>num;
        getchar();
        string temp;
        for(int i=0;i<num;i++)
        {
            getline(cin,temp);
            org.push_front(temp);
        }
        for(int i=0;i<num;i++)
        {
            getline(cin,temp);
            after.push_front(temp);
        }

        que();
        cout<<endl;

    }

}
