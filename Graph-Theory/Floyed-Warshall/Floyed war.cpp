#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 100
#define read(a) scanf("%d",&a)
#define Clear(a,b) memset(a,b,sizeof(a))
#define INF 1e8+7

int G[Max][Max];
int Next[Max][Max];
vector<int> path;

void Floyed_Warshall(int vertex)
{
    for(int i=1;i<=vertex;i++)
    {
        for(int j=1;j<=vertex;j++)
        {
            Next[i][j]=j;
        }
    }

    for(int k=1;k<=vertex;k++)
    {
        for(int i=1;i<=vertex;i++)
        {
            for(int j=1;j<=vertex;j++)
            {
                if(G[i][j]>G[i][k]+G[k][j])
                {
                    {
                        G[i][j]=G[i][k]+G[k][j];
                        Next[i][j]=Next[i][k];
                       // cout<<Next[i][j]<<endl;
                    }
                }
            }
        }
    }
}

void Find_path(int src, int des)
{
    path.clear();
    path.push_back(src);
    while(src!=des)
    {
        src  = Next[src][des];
        //cout<<src<<endl;
        path.push_back(src);
    }

    for(int i=0;i<path.size();i++)
    {
        printf("%d ",path[i]);
    }
    printf("\n");

    return ;
}

int main()
{
    //freopen("in.txt","r",stdin);

    int test,u,v,w,vertex,edge;
    read(test);

    for(int Case=1;Case<=test;Case++)
    {
        for(int i=1;i<=Max;i++)
        {
            for(int j=1;j<=Max;j++)
            {
                G[i][j]=INF;
            }
        }

        for(int i=0;i<100;i++)
            G[i][i]=0;
        read(vertex);  read(edge);

        for(int i=0;i<edge;i++)
        {
            read(u);read(v);read(w);

            G[u][v]=w;
        }

        Floyed_Warshall(vertex);

        int m,n;

        while( cin>>m>>n)
        {


            printf("%d\n",G[m][n]);

            cout<<"path"<<endl;
            Find_path(m,n);


        }




    }



    return 0;
}
