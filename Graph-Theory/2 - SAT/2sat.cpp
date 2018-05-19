#include<iostream>
#include<bits/stdc++.h>

#define ll long long int
#define lim 8010
#define Clear(a,b) memset(a,b,sizeof(a))

// A V B  --> (A'->B) and (B'->A) 

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

vector<int> res;

//double nodes needed normally
void TwoSAT(int n) //n=nodes (some change may be required here)
{
    TarjanSCC(n);

    res.clear();

    int i;
    for(i=0;i<n;i+=2)
    {
        //cout<<group_id[i]<<" "<<group_id[i+1]<<endl;
        if(group_id[i]==group_id[i+1])
        {
            printf(" No\n");
            return ;
        }
        if(group_id[i]<group_id[i+1]) //Checking who is lower in Topological sort
        {
            res.push_back(i/2 + 1);
        }
    }

    int ss = res.size();

    printf(" Yes\n%d",ss);

    for(int i=0;i<ss;i++)
    {
        printf(" %d",res[i]);
    }

    printf("\n");

    return;
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

int complement(int n)
{
    if(n%2) return n-1;
    return n+1;
}

int main()
{
    int test, n, m,val1,val2;
    char ch1,ch2;
    int p,q;

    scanf("%d",&test);

    for(int Case=1;Case<=test;Case++)
    {
        scanf("%d %d",&n,&m);

        initialize(2*m);

        for(int i=0;i<n;i++)
        {
            scanf(" %c %d %c %d",&ch1,&val1,&ch2,&val2);

            if(ch1=='+')
            {
                p=2*val1 -2;
            }
            else
            {
                 p=2*val1+1 -2;
            }

            if(ch2=='+')
            {
                 q=2*val2 -2;
            }
            else
            {
                 q=2*val2+1 -2;
            }

          //  cout<<p<<" "<<q<<endl;

            add(complement(p),q);
            add(complement(q),p);

        }

        printf("Case %d:",Case);
        TwoSAT(2*m);
    }

    return 0;
}

