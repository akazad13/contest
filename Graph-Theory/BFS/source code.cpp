/* A K Azad
     CSE-13
     RUET.

*/


//Directed Graph............................

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define max 10000
vector<int> edge[max];
int parent[max];

void bfs(int n,int src)
{
	queue<int>Q;
	Q.push(src);
	int visited[max]={0},level[max];
	visited[src]=1;
    level[src]=0;
	while(!Q.empty())
	{
		int u=Q.front();
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i];
			if(!visited[v])
			{
			    cout<<v<<endl;
				level[v]=level[u]+1;
				parent[v]=u;
				visited[v]=1;
				Q.push(v);
			}
		}
		Q.pop();
	}
	for(int i=1;i<=n;i++)
		printf("%d to %d distance %d\n",src,i,level[i]);
}



int main()
{
    freopen("input1.txt","r",stdin);


    int in[max]={0};
    int out[max]={0};

    int N,E;

    cin>>N>>E;

    for(int i=1;i<=E;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        edge[n1].push_back(n2);
    }

    bfs(N,1);

    printf("Enter a node number to find its path from source: ");
    int node;
    while(cin>>node,node)
    {
        cout<<"node "<<node<<":";
        while(parent[node]>=1)
        {
            cout<<" "<<parent[node];
            node  = parent[node];
        }
        cout<<"\n";
    }

    return 0;

}



