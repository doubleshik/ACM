#include <iostream>
#include <list>
#include <cstdio>
#include <iterator>
using namespace std;

int rec[1000000]={0};
list<int> lst;
list<int>::iterator team[2000];
int main()
{
    int tst=0;
    int ca=0;
    int t;
    while(cin>>t &&t!=0)
    {
        lst.clear();
        int num,temp;
        for(int i=0;i<t;i++)
        {
            team[i] = lst.end();
            cin>>num;
            for(int j=0;j<num;j++)
            {
                cin>>temp;
                rec[temp]=i;

            }
        }
        cout << "Scenario #" << ++tst << endl;
        string cmd;
        while(cin>>cmd && cmd!="STOP")
        {
            int tmp;
            if(cmd=="ENQUEUE")
            {
                cin>>tmp;
                if(team[rec[tmp]] !=lst.end())
                {
                    ++team[rec[tmp]];
                    team[rec[tmp]] = lst.insert(team[rec[tmp]],tmp);
                }
                else
                {
                    team[rec[tmp]] = lst.insert(team[rec[tmp]],tmp);
                }
            }
            else if(cmd=="DEQUEUE")
            {
                int top  =  lst.front();
                if(team[rec[top]]==lst.begin())
                {
                    team[rec[top]]=lst.end();
                }
                lst.pop_front();
                cout<<top<<endl;
            }
        }
        cout<<endl;

    }


    return 0;
}
