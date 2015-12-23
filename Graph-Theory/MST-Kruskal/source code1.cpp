#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 10010

struct edge
{
	int u,v;
	long long int w;
	bool operator < ( const edge& p ) const
	{
		return w < p.w;
	}
};
int par[Max];
vector<edge>e;
int find(int r)
{
   return (par[r]==r) ? r:  find(par[r]);
}
long long int mst(int n)
{
	sort(e.begin(),e.end());
	for(int i=1;i<=n;i++)par[i]=i;

	int count=0;
	long long int total_cost=0;
	for(int i=0;i<(int)e.size();i++)
	{
		int u=find(e[i].u);
		int v=find(e[i].v);
		if(u!=v)
		{
			par[u]=v;
			count++;
			total_cost+=e[i].w;
			if(count==n-1) break;
		}
	}
	return total_cost;
}

int main(){
//	READ("in");
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		long long int w;
		scanf("%d %d %lld",&u,&v,&w);
		edge data;
		data.u=u;
		data.v=v;
		data.w=w;
		e.push_back(data);
	}
	printf("%lld\n",mst(n));
	return 0;

}
