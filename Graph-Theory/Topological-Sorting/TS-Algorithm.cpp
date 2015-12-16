#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define max 1000

bool G[max][max]; //graph representation using Matrix
int indeg[max], Topsort[max];  //for stroing indegree and sorting sequense

void CreatGraph(int node, int edge) //creating graph
{
    memset(G,0,sizeof(G));  //clearing graph
    int u,v;
    for(int i=0;i<edge;i++)
    {
        scanf("%d %d",&u,&v);
        G[u][v]=true;
    }
}

int find_indeg(int m,int n)   //find indegree for each vertex
{
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(G[i][m])
            res++;
    }

    return res;
}

void DisplayTopsort(int node)  //Display the sorting sequence
{
    for(int i=0;i<node;i++)
    {
        printf("%d ",Topsort[i]);
    }
    printf("\n");
}

int main()
{
    int node, edge; //node from 1 to n

    while(cin>>node>>edge)
    {
        if(node==0 && edge==0)
            break;

        queue<int> vertex;
        memset(indeg,0,sizeof(indeg));
        memset(Topsort,-1,sizeof(Topsort));

        CreatGraph(node,edge);

        for(int i=1;i<=node;i++)
        {
            indeg[i]= find_indeg(i,node);
            if(indeg[i]==0)   //if no indegree that is no dependecy ,, we need to select them 1st
            {
                vertex.push(i);
            }
        }

        int j=0;

        while(!vertex.empty())
        {
            int top = vertex.front(); vertex.pop();

            Topsort[j++]=top;

            for(int i=1;i<=node ;i++)
            {
                if(G[top][i])
                {
                    G[top][i]=false;  //destroying the connection between adjacency vertices
                    indeg[i]--;    // decreament v'th indegree by one
                    if(indeg[i]==0)
                    {
                        vertex.push(i);
                    }
                }
            }

        }

        DisplayTopsort(node);

    }

    return 0;
}

