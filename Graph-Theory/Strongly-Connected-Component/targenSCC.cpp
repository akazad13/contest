#include<iostream>
#include<bits/stdc++.h>

#define ll long long int
#define lim 8010
#define Clear(a,b) memset(a,b,sizeof(a))


using namespace std;
//0 based
vector<int> adj[2*lim]; //2*lim for true and false argument(only adj should be cleared)
int col[2*lim],low[2*lim],desc[2*lim],timer;
int group_id[2*lim],components;//components=number of components, group_id = which node belongs to which node
stack<int>S;

void scc(int u)
{
    int i,v,now;
    col[u]=1;
    low[u]=desc[u]=timer++;
    S.push(u);

    int len = adj[u].size();

    for(int i=0;i<len;i++)
    {
        v=adj[u][i];
        if(col[v]==1)
            low[u]=min(low[u],desc[v]);
        else if(col[v]==0)
        {
            scc(v);
            low[u]=min(low[u],low[v]);
        }
    }

    //SCC checking...
    if(low[u]==desc[u]) //find head and hence component
    {
        do
        {
            now=S.top();S.pop();
            group_id[now]=components;  // give component number
            col[now]=2; //Completed...
        }while(now!=u);

        components++; // this number component done... next number
    }
}

int TarjanSCC(int n) //n=nodes (some change may be required here)
{
    int i;
    timer=components=0;
    Clear(col,0);

    while(!S.empty())
        S.pop();

    for(int i=0;i<n;i++)
    {
        if(col[i]==0)
            scc(i);
    }
}

void add(int ina,int inb)
{
    adj[ina].push_back(inb);
}


void initialize(int n)
{
    for(int i=0;i<n;i++)
        adj[i].clear();
}


int main()
{
   
}

