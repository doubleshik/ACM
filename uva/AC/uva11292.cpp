    #include <iostream>
    #include <algorithm>
    #include <cstdio>
    using namespace std;

    const int maxn = 30000;
    int brave[maxn];
    int dragon[maxn];

    int main()
    {
        int n,m;
        while(cin>>n>>m && n&& m)
        {
            for(int i=0;i<n;i++)
            {
                cin>>dragon[i];
            }
            for(int i=0;i<m;i++)
            {
                cin>>brave[i];
            }
            sort(dragon,dragon+n);
            sort(brave,brave+m);
            int ans=0;
            int i=0,j;
            for(j=0 ;j<m;j++)
            {
                if(brave[j]>=dragon[i])
                {
                    ans+=brave[j];
                    i++;
                    if(i==n)break;
                }
            }
            if(i>=n)
                printf("%d\n",ans);
            else
                printf("Loowater is doomed!\n");
        }

        return 0;
    }
