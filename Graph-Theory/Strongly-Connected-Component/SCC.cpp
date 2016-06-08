#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define read(a) scanf("%d",&a)
#define Lread(a) scanf("%lld",&a)
#define Uread(a) scanf("%llu",&a)
#define Dread(a) scanf("%lf",&a)
#define write(a) printf("%d\n",a)
#define Case(a) printf("Case %d: ",a)

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define PR pair<int,int>
#define MP(a,b) make_pair(a,b)

#define Clear(a,b) memset(a,b,sizeof(a))
#define Max 100000


VI G[Max],rev[Max];
int color[Max];
bool visited[Max];
stack<int> stk;
VI component[Max];

void rev_graph(int vertex)
{
    int i,j;
    rep(i,0,vertex+1)
        rev[i].clear();
    rep(i,0,vertex+1)
    {
        rep(j,0,G[i].size())
        {
            int v = G[i][j];
            rev[v].pb(i);
        }

    }
    return ;
}

void DFS_visit(int u)
{
    color[u]=1;
    int i;
    rep(i,0,G[u].size())
    {
        int v = G[u][i];
        if(color[v]==0)
        {
            DFS_visit(v);
        }
    }
    stk.push(u);
    return ;
}

void DFS_visit2(int src, int mark)
{
    component[mark].pb(src);

    visited[src]=1;

    int i,v;
    rep(i,0,rev[src].size())
    {
        v = rev[src][i];
        if(visited[v]==0)
        {
            DFS_visit2(v,mark);
        }
    }
    return ;
}


void FindSCC(int vertex)
{
    //stk.clear();
    Clear(visited,0);
    Clear(color,0);
    int i;

    rep(i,0,vertex+1)
        component[i].clear();



    rep(i,1,vertex+1)
    {
        if(color[i]==0)
        {
            DFS_visit(i);
        }
    }

    rev_graph(vertex);

    int mark=0;
    int u,j;
    while(!stk.empty())
    {
        u = stk.top(); stk.pop();
        if(visited[u]==0)
        {
            mark++;
            DFS_visit2(u,mark);
        }
    }

    cout<<mark<<endl;

    rep(i,1,mark+1)
    {
        rep(j,0,component[i].size())
        {
            printf("%d ",component[i][j]);
        }
        printf("\n");
    }
    return ;
}



int main()
{
    int test;
    int Case,i,j,vertex,u,v,edge;
    read(test);

    rep(Case,1,test+1)
    {
        read(vertex); read(edge);
        rep(i,0,vertex+1)
            G[i].clear();
        rep(i,0,edge)
        {
            read(u);read(v);
            G[u].pb(v);


        }
        FindSCC(vertex);
    }

    return 0;
}
