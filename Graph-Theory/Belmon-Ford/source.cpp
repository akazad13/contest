#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define PA pair<int,int>
#define MP(a,b) make_pair(a,b)
#define Max 100000
#define read(a) scanf("%d",&a)
#define Clear(a,b) memset(a,b,sizeof(a))

struct node
{
    int u,v,w;
    node(int a, int b, int c)
    {
        u=a;v=b;w=c;
    }
};

vector< node > G;
int d[Max];

int belmon_ford(int src,int N,int des,int edge)
{
    int u,v,w;
    Clear(d,INFINITY);
    d[src]=0;
    bool Neg_cycle = false;
    bool update;

    for(int step=1;step<=N;step++)
    {
        update=true;
        for(int i=0;i<edge;i++)
        {
            u = G[i].u; v = G[i].v; w = G[i].w;
            if(d[v]>d[u]+w)
            {
                update = false;
                if(step==N)
                    Neg_cycle=true;
                d[v]=d[u]+w;

            }
        }

        if(update)
            break;
    }

    if(Neg_cycle)
        return (-1*INT_MAX);
    else
        return d[des];


}


int main()
{
    int test;
    int u,v,w,vertex,edge,src,des;
    read(test);

    for(int Case =1 ;Case<=test; Case++)
    {
        read(vertex); read(edge);

        for(int i=0;i<edge;i++)
        {
            read(u); read(v); read(w);
            G.push_back(node(u,v,w));
        }
        read(src);
        read(des);
        int res = belmon_ford(src,vertex,des,edge);
        if(res==(-1*INT_MAX))
            printf("Case %d: Negative cycle detected\n",Case);
        else
            printf("Case %d: %d\n",Case,res);
    }




    return 0;
}
