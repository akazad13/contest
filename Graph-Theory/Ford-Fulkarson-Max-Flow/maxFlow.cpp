// O(VE^2)
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

#define pi pair<int,int>
#define pii pair<int, pair<int, int> >
#define mp(a,b) make_pair(a,b)

#define Clear(a,b) memset(a,b,sizeof(a))

#define Max 1002

int residualCapacity[Max][Max];
int capacity[Max][Max];
VI G[Max];
VI path;
bool vis[Max];

vector< VI > paths;

int par[Max];

bool bfs(int vertex, int source, int sink)
{
    Clear(vis,0);
    queue<int> Q;
    vis[source]=true;
    Q.push(source);

    bool isPath= false;
    int i;

    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();

        rep(i,1,vertex+1)
        {
            if(vis[i]==0 && residualCapacity[u][i]>0)
            {
                par[i]=u;
                vis[i]=true;
                Q.push(i);

                if(i==sink)
                {
                    isPath=true;
                    break;
                }
            }
        }


    }

    return isPath;

}

int FordFulkarson(int vertex, int source, int sink)
{

    int i,j;

    rep(i,1,vertex+1)
    {
        rep(j,1,vertex+1)
        {
            residualCapacity[i][j] = capacity[i][j];
        }
    }

    path.clear();
    paths.clear();

    int max_flow = 0;

    while(bfs(vertex,source,sink))
    {
        int v = sink;
        int flow = INT_MAX;
        while(v!=source)
        {
            path.push_back(v);
            int u = par[v];

            flow = min(flow,residualCapacity[u][v]);
            v=u;
        }
        path.push_back(source);
        max_flow+=flow;
        reverse(path.begin(),path.end());

        paths.push_back(path);
        path.clear();


        v = sink;
        while(v!=source)
        {
            int u = par[v];
            residualCapacity[u][v]-=flow;
            residualCapacity[v][u]+=flow;
            v=u;
        }
    }

    return max_flow;



}

int main()
{
    //freopen("input.txt","r",stdin);

    int vertex;
    int source, sink;
    int edge;
    int u,v,i,j,cap;
    Clear(capacity,0);

    read(vertex); read(edge);
    read(source); read(sink);



    rep(i,0,edge)
    {
        read(u); read(v);
        read(cap);
        capacity[u][v]=cap;
    }

    int ret  = FordFulkarson(vertex, source, sink);

    printf("%d\n",ret);

    return 0;
}

