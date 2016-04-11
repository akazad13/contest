#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define lld long long int
#define rep(i,a,b) for(i=a;i<b;i++)
#define read(a) scanf("%d",&a)
#define Clear(a,b) memset(a,b,sizeof(a))
#define Max 10005


vector<int> G[Max];
int node,edge;
bool visited[Max];
int d[Max];
int cnt[Max];
int low[Max];
vector<pair<int,int> > bridge;
map<int, map<int, int> > isBridge;
int parent[Max];

void find_bridge(int time, int u)
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
          //  cout<<u<<" "<<v<<endl;
            parent[v]=u;
            find_bridge(time,v);
            low[u] = min(low[u],low[v]);
            if(d[u]<low[v])
            {
                bridge.push_back(make_pair(u,v));
               // cout<<u<<" "<<v<<endl;;
                isBridge[u][v]=isBridge[v][u]=1;
            }
        }
    }

    return ;


}

void dfs()
{
    Clear(visited,0);
   // Clear(articulation_point,0);
    isBridge.clear();
    bridge.clear();
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
            find_bridge(time,i);
        }
    }
    return ;

}

int find(int u)
{
    if(u == parent[u]) return u;
    else return parent[u] = find(parent[u]);
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
        //cout<<"--------------------------"<<endl;

        dfs();

        rep(i,0,node)
        {
            parent[i]=i;
        }

        rep(i,0,node)
        {
            rep(j,0,G[i].size())
            {
                v = G[i][j];

                if(isBridge[i][v]!=1)
                {
                    //cout<<u<<" "<<v<<endl;
                    int u = find(i);

                    v = find(v);


                    if( u != v)
                    {
                        parent[u] = v;
                    }
                }
            }
        }

        Clear(cnt, 0);

        //cout<<"s : "<<bridge.size()<<endl;

        rep(i,0, bridge.size())
        {
            int u = bridge[i].first;
            int v = bridge[i].second;

            u = find(u);

            v = find(v);


            //dump(u); dump(v);
           // cout<<u<<" "<<v<<endl;

            cnt[u]++;
            cnt[v]++;
        }
       // cout<<cnt[0]<<endl;


        int res = 0;

        rep(i,0, node)
        {
           // cout<<i<<endl;
            if(cnt[i] == 1)
            {
                res++;
              //  cout<<i<<" "<<res<<endl;
            }
        }
        //cout<<res<<endl;


        //ret = count of leaf

        res = (res + 1)/2;

        printf("Case %d: %d\n",Case,res);
        }


    return 0;
}

