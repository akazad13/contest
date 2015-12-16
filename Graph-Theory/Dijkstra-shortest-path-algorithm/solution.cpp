#include<iostream>
#include<bits/stdc++.h>

using namespace std;


#define mx 100002
vector<int> g[mx],cost[mx];
struct node
{
    int u;
    long long int w;
    node(int a,long long int b){u=a; w=b;}
    bool operator > ( const node& p ) const { return w > p.w; }
};
long long int d[mx];
int par[mx];
int dijkstra(int n)
{
    memset(d,63,sizeof(d));
    memset(par,-1,sizeof(par));
    priority_queue <node,vector<node>, greater<node> > q;
    q.push(node(1,0));
    d[1]=0;
    while(!q.empty())
    {
        node top=q.top(); q.pop();
        int u=top.u;

        cout<<top.u<<" "<<top.w<<endl;

        if(u==n) return d[n];
        for(int i=0;i<(int)g[u].size();i++)
        {
            int v=g[u][i];
            if(d[u]+cost[u][i] < d[v])
            {
                d[v]=d[u]+cost[u][i];
                par[v]=u;
                q.push(node(v,d[v]));
            }
        }
    }
    return -1;
}
int main(){

    //freopen("Disec.txt","r",stdin);
  //  freopen("de.txt","w",stdout);

    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int u,v;
        int w;
        cin>>u>>v>>w;
        g[u].push_back(v);
        g[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);

    }
    int ret=dijkstra(n);
    cout<<ret<<endl;
    if(ret==-1) puts("-1\n");
    else
    {
        int u=n;
        vector<int> out;
        while(u!=-1)
        {
            out.push_back(u);

            u=par[u];

        }
        reverse(out.begin(),out.end());
        for(int i=0;i<(int)out.size();i++)
           cout<<out[i]<<" ";
        //puts("");
        cout<<"\n";

    }
}
