#include <iostream>
using namespace std;
const int maxn = 30;
int first[maxn];
int last[maxn];

int main()
{
     int tst;
    cin>>tst;
    while(tst--)
    {
        int Nw;
        cin>>Nw;
        cin.ignore();
        memset(words,'\0',sizeof(words));
        for(int i=0;i<Nw;i++)
        {
            gets(words);
            int a = words[strlen(words)-1]-'a';
            int b = words[0]-'a';
            first[a]++;
            last[b]++;

        }

    }
    return 0;
}
