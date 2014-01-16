//Thu Jan  2 22:20:48 2014
//Author:Minshik
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <memory.h>
#include <cctype>
#include <iomanip>
#include <cmath>
using namespace std;

// k^2 = (n+n^2)/2
int main()
{

    int cnt = 0;
    long long n=2;
    while(cnt<10)
    {
        long long d = (n+pow(n,2))/2;
        long long c = sqrt(d);
        if(  c*c == d  )
        {
            cout<<setw(10)<<c << setw(10)<<n<<endl;
            cnt++;
        }
        n++;
    }

    return 0;
}
