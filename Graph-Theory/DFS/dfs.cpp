#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 100010
#define Clear(a,b) memset(a,b,sizeof(a))
#define si(a) scanf("%d",&a)

vector<int> g[Max];
int vis[Max];
int d[Max];

void dfs(int u)
{
    vis[u]=1;
    int len = g[u].size();
    for(int i=0;i<len;i++)
    {
        int v = g[u][i];
        if(vis[v]==0)
        {
            dfs(v);
        }
    }
}

int main()
{
    int test,n,e,u,v;
    si(test);

    for(int Case = 1;Case<=test;Case++)
    {
        si(n); si(e);
        for(int i=0;i<=n;i++)
        {
            g[i].clear();
            vis[i]=0;
        }

        for(int i=0;i<e;i++)
        {
            si(u); si(v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i);
            }
        }
    }
    return 0;
}

