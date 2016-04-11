#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define lld long long int
#define rep(i,a,b) for(i=a;i<b;i++)
#define read(a) scanf("%d",&a)
#define Clear(a,b) memset(a,b,sizeof(a))
#define Max 100000


vector<int> G[Max];
int node,edge;
bool visited[Max];
int d[Max];
int low[Max];
bool articulation_point[Max];
int parent[Max];

void find_articulation(int time, int u)
{
    time +=1;
    low[u]=d[u]=time;
    visited[u]=true;
   // cout<<u<<endl;
    int child = 0;
    int i,v;

    rep(i,0,G[u].size())
    {
        v = G[u][i];
        if(v==parent[u]) continue;

        if(visited[v]) //back edge
        {
            low[u] = min(low[u],d[v]);
        }
        else //tree edge
        {
            parent[v]=u;
            find_articulation(time,v);
            low[u] = min(low[u],low[v]);
            if(d[u]<=low[v] && parent[u]!=-1)
                articulation_point[u]=true;
            child+=1;
        }

        if(child>1 && parent[u]==-1)
        {
            articulation_point[u]=true;
        }
    }

    return ;


}

void dfs()
{
    Clear(visited,0);
    Clear(articulation_point,0);
    Clear(d,0);
    Clear(low,0);
    Clear(parent,-1);

    int time = 0;
    int i;

    rep(i,0,node)
    {
        if(!visited[i])
        {
           // cout<<"i: "<<i<<endl;
            find_articulation(time,i);
        }
    }
    return ;

}

int main()
{
    int test,Case,i,j,u,v;
    read(test);
    rep(Case,1,test+1)
    {
        read(node);
        read(edge);

        rep(i,0,node+1)
            G[i].clear();

        rep(i,0,edge)
        {
            read(u); read(v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        dfs();

        rep(i,0,node)
        {
           // cout<<000<<" ";
            if(articulation_point[i])
                printf("%d ",i);
        }
        printf("\n");
    }


    return 0;
}
