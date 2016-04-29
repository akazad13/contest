#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 1000
#define rep(i,p,n) for( i = p; i<n;i++)

bool graph[Max][Max];
int color[Max];

void print(int vertex,int v, int k)
{
    int i;
    rep(i,0,vertex)
    {
        if(color[i])
            cout<<color[i]<<" ";
    }
    cout<<"\t\tfor : "<<v<<" chose: "<<k;
    cout<<endl;
}

bool safe(int v,int chosen_color,int vertex)
{
    int i,j;
    rep(i,0,vertex)
    {
        if(graph[v][i] && chosen_color == color[i])
            return false;
    }
    return true;
}

bool solve(int v, int No_color, int vertex)
{

    if(v>=vertex)
        return true;
    int i;
    rep(i,1,No_color+1)
    {
        if(safe(v,i,vertex))
        {
            //cout<<v<<endl;
            color[v]=i;
            if(solve(v+1,No_color,vertex))
                return true;
            cout<<"ok"<<endl;

            color[v]=0;
        }
        print(vertex,v,i);
    }

    return false;
}

int main()
{
    memset(graph,false,sizeof(graph));
    memset(color,0,sizeof(color));
    int No_color,i;
    int vertex, edge,u,v;
    cin>>vertex>>edge;

    rep(i,0,edge)
    {
        cin>>u>>v;
        graph[u][v]=true;
        graph[v][u]=true;

    }

    cout<<"number of color: ";
    cin>>No_color;

    bool ret = solve(0,No_color,vertex);

    if(ret==false)
        cout<<"Not possible"<<endl;
    else
    {
        rep(i,0,vertex)
        {
            cout<<i<<": "<<color[i]<<" \n";
        }
        cout<<endl;

        //printsol(n);
    }

    return 0;
}

