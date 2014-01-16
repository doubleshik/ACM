    #include <iostream>
    #include <memory.h>
    using namespace std;


    int N,R;
    const int maxn = 300;
    int G[maxn][maxn];
    int du[maxn];
    int vis[maxn];

    void dfs(int u)
    {
        vis[u]=1;
        for(int i=0;i<N;i++)
        {
            if(G[u][i] &&!vis[i])
            {
                dfs(i);
            }
        }
    }


    bool DFS()
    {
        int cnt=0;
        for(int i=0;i<N;i++)
        {
            if(du[i] && !vis[i])
            {
                dfs(i);
                cnt++;
            }
            if(cnt>1)return false;
        }
        return true;
    }
    bool euler()
    {
        for(int i=0;i<N;i++)
        {
            if(du[i]%2==1)
                return false;
        }
        return true;

    }

    int main()
    {
        while(cin>>N>>R)
        {
                int ta,tb;

                for(int i=0;i<R;i++)
                {
                    cin>>ta>>tb;
                    G[ta][tb]=G[tb][ta]=1;
                    du[ta]++;du[tb]++;
                }
                bool flag = true;


                if(R==0){flag=false;cout<<"Not Possible"<<endl;}

                if(!DFS()){flag=false;cout<<"Not Possible"<<endl;}


                if(flag)
                {
                    if(!euler())
                    {
                        cout<<"Not Possible"<<endl;
                    }
                    else
                    {
                        cout<<"Possible"<<endl;
                    }
                }

                memset(G,0,sizeof(G));
                memset(vis,0,sizeof(vis));
                memset(du,0,sizeof(du));
                //memset(out,0,sizeof(out));
        }

        return 0;
    }
