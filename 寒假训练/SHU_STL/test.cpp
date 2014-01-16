#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 1500

string s1[MAXN],s2;
string s[MAXN*MAXN];

int main()
{
    freopen("IN","r",stdin);
	int t,a,b,x=1;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		getline(cin,s2,'\n');
		for(int i = 0; i < a; i++)
			getline(cin,s1[i],'\n');
		for(int i = 0; i < b; i++)
		{
			getline(cin,s2,'\n');
			for(int j = 0; j < a; j++)
				s[i*a+j]=s1[j]+s2;
		}
		sort(s,s+a*b);
		int n = a*b;
		for(int i = 1; i < a*b; i++)
			if(s[i]==s[i-1])n--;
		cout<<"Case "<<x++<<": "<<n<<endl;
	}
	return 0;
}

