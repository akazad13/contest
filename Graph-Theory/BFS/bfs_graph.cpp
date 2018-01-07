#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 10000 // node limit
#define Clear(a,b) memset(a,b,sizeof a)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define ll long long int

vector<int> g[Max];
int parent[Max];

void bfs(int src, int n)
{
    bool vis[Max];
    int level[Max]; // level = distance from source
    Clear(vis,0);
    queue<int>Q;
	Q.push(src);

	vis[src]=1;
    level[src]=0;
	while(!Q.empty())
	{
		int u=Q.front(); Q.pop();
		int len = g[u].size();
		for(int i=0;i<len;i++)
		{
			int v=g[u][i];
			if(!vis[v])
			{
				level[v]=level[u]+1;
				parent[v]=u;
				vis[v]=1;
				Q.push(v);
			}
		}
	}
}
int main()
{
    int test,n,e,u,v; // n=node, e=edge

    si(test);

    for(int Case=1;Case<=test;Case++)
    {
        si(n); si(e);


        for(int i=0;i<=n;i++)
            g[i].clear();

        for(int i=1;i<=e;i++)
        {
            si(u); si(v);
            g[u].push_back(v);
            g[v].push_back(u); // for bidirectional
        }
        bfs(1,n);
    }
    return 0;
}
