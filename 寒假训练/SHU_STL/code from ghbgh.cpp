//Orz ghbgh!!!

//A
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 1000000+1

vector<int> a[MAXN];
int main()
{
	int n,m;
	int x,y;
	while(cin>>n>>m)
	{
		for(int i = 0; i < n; i++)
		{
			cin>>x;
			a[x].push_back(i+1);
		}
		for(int i = 0; i < m; i++)
		{
			cin>>y>>x;
			if(a[x].size()<y)
				cout<<0<<endl;
			else
				cout<<a[x][y-1]<<endl;
		}
		for(int i = 0; i < MAXN; i++)
			a[i].clear();
	}
	return 0;
}

//B
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;
#define ll long long

int main()
{
	int t;
	ll n;
	char c;
	string s;
	stack<ll> min_r, max_r;
	cin>>t;
	getline(cin,s,'\n');
	while(t--)
	{
		getline(cin,s,'\n');
		istringstream ss(s);
		ss>>n;
		min_r.push(n); max_r.push(n);
		while(ss>>c)
		{
			ss>>n;
			if(c=='+')
			{
				max_r.top()+=n;
				min_r.push(n);
			}else{
				min_r.top()*=n;
				max_r.push(n);
			}
		}
		
		while(min_r.size()>1)
		{
			n = min_r.top();
			min_r.pop();
			min_r.top()+=n;
		}
		while(max_r.size()>1)
		{
			n = max_r.top();
			max_r.pop();
			max_r.top()*=n;
		}
		cout<<"The maximum and minimum are "<<max_r.top()<<" and "<<min_r.top()<<"."<<endl;
		min_r.pop();
		max_r.pop();
	}
	return 0;
}

//C
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXV 1000000
#define MAXN 100020
int a[MAXN], b[MAXN];

int prime[MAXN];
int vis[MAXV];
int p;

void mktable()
{
	for(int i = 2; i < MAXV; i++) if(!vis[i])
	{
		prime[p++]=i;
		if(i<1000) for(int j = i*i; j < MAXV; j+=i) vis[j]=1;
	}
	for(int i = 0; i < MAXN; i+=2)
	{
		int found=0;
		for(int j = 0; j < p; j++)
		{
			if(*lower_bound(prime,prime+p,prime[j]+i)==prime[j]+i)
			{
				found=1;
				a[i]=prime[j]+i;
				b[i]=prime[j];
				break;
			}
		}
		//if(!found) cout<<i<<endl;
	}
}

int main()
{
	mktable();
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n>=0)
			cout<<a[n]<<' '<<b[n]<<endl;
		else
			cout<<b[-n]<<' '<<a[-n]<<endl;
	}
	return 0;
}

//D
#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
#define MAXN 5000

priority_queue<int, vector<int>,greater<int> > q;
int main()
{
	int a,n,s,t1,t2;
	while(cin>>n)
	{
		if(n==0)break;
		for(int i = 0; i < n; i++)
		{
			cin>>a;
			q.push(a);
		}
		s = 0;
		while(q.size()>1)
		{
			t1 = q.top(); q.pop();
			t2 = q.top(); q.pop();
			s+=t1+t2;
			q.push(t1+t2);
		}
		cout<<s<<endl;
		q.pop();
	}
	return 0;
}

//E
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define MAXN 50

struct mat{
	int d[MAXN][MAXN];
	void clear(){memset(d,0,sizeof(d));}
	bool operator==(const mat& t){return !memcmp(d,t.d,sizeof(d));}
}now[4];

bool comp(const mat& a, const mat& b)
{
	return memcmp(a.d,b.d,sizeof(a.d))<0;
}


int main()
{
	int n,x,y;
	char c;
	while(cin>>n)
	{
		vector<mat> m;
		if(!n)break;
		for(int i=0;i<4;i++)
			now[i].clear();
		m.push_back(now[0]);
		bool wins=false;
		for(int i = 0; i < 2*n; i++)
		{
			cin>>x>>y>>c;
			if(wins)continue;
			now[0].d[x-1][y-1] = c=='+'?1:0;
			now[1].d[n-y][x-1] = c=='+'?1:0;
			now[2].d[n-x][n-y] = c=='+'?1:0;
			now[3].d[y-1][n-x] = c=='+'?1:0;
			
			vector<mat>::iterator it = lower_bound(m.begin(),m.end(),now[0],comp);
			if(now[0]==*it)
			{
				wins=true;
				cout<<"Player "<<(i+1)%2+1<<" wins on move "<<i+1<<endl;
			}
			m.insert(it,now[0]);
			for(int i=1;i<4;i++) m.insert(lower_bound(m.begin(),m.end(),now[i],comp),now[i]);
		}
		if(!wins) cout<<"Draw"<<endl;
	}
	return 0;
}

//F
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAXN 1500

string s1[MAXN],s2;
string s[MAXN*MAXN];

int main()
{
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

//G
#include <iostream>
#include <string>
#include <set>
using namespace std;

string s[120000];
set<string> st;
int main()
{
	int n=0;
	while(cin>>s[n])st.insert(s[n++]);
	for(int i = 0; i < n; i++)
	for(int j = 1; j < s[i].length(); j++)
		if(st.count(s[i].substr(0,j))
		&& st.count(s[i].substr(j,s[i].length()-j)))
		{
			cout<<s[i]<<endl;
			break;
		}
	return 0;
}

//H
#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<string, string> m;
	string s1,s2;
	while(getline(cin,s1,'\n'))
	{
		if(s1=="")break;
		istringstream is(s1);
		is>>s1>>s2;
		m[s2]=s1;
	}
	while(getline(cin,s1,'\n'))
	{
		if(!m.count(s1))
			cout<<"eh"<<endl;
		else
			cout<<m[s1]<<endl;
	}
	return 0;
}

//I
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

int main()
{
	string s;
	list<char> a;
	while(getline(cin,s,'\n'))
	{
		a.clear();
		list<char>::iterator it=a.begin();
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i]=='[')
				it=a.begin();
			else if(s[i]==']')
				it=a.end();
			else
				a.insert(it, s[i]);
		}
		for(it=a.begin(); it!=a.end(); it++)
			cout<<*it;
		cout<<endl;
	}
	return 0;
}

//J
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>

using namespace std;

int main()
{
	int cases;
	cin>>cases;
	getchar();
	char c = 0;
	while(cases--)
	{
		stack<int> p;
		bool correct = true;
		while((c = getchar())!='\n' && c!= EOF)
		{
			if(correct)
			{
				if(c == '(' || c == '[')
					p.push(c);
				else if(p.empty())
					correct = false;
				else if(c == ')')
					if(p.top() == '(') p.pop(); else correct = false;
				else if(c == ']')
					if(p.top() == '[') p.pop(); else correct = false;
				else correct = false;
			}
		}
		if(!p.empty())
		{
			correct = false;
		}
		if(correct)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}

