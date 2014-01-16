#include <iostream>
using namespace std;

int main()
{
    int tst;
    cin>>tst;
    cin.ignore();
    string code;
    while(tst--)
    {
        getline(cin,code);

        if(code == "1" || code == "4" || code =="78")
        {
            cout<<"+"<<endl;
        }
        else if(code[code.size()-1]=='5' && code[code.size()-2]=='3')
        {
            cout<<"-"<<endl;
        }
       else if (code[0] == '9' && code[code.size() - 1] == '4')
        {
            cout << '*' << endl;
        }
        else if (code[0] == '1' && code[1] == '9' && code[2] == '0')
        {
            cout << '?' << endl;
        }
    }

    return 0;
}
