#include<bits/stdc++.h>
using namespace std;
#define si(a) scanf("%d",&a)
int par[100005], val[100005], rnk[100010], idx[100010];

int Find(int u)
{
    if(par[u]==u)
        return u;
    return par[u] = Find(par[u]);
}

void Union(int p, int q)
{
    int u = Find(p);
    int v = Find(q);

    if(u==v)
        return ;

    if(rnk[u]>=rnk[v])
    {
        par[v] = u;
        rnk[u]+=rnk[v];
    }
    else
    {
        par[u] = v;
        rnk[v]+=rnk[u];
    }
    return ;
}

int main()
{
    int t,n,m,a,b,c;
    si(t);

    for(int Case=1; Case<=t; Case++)
    {
        si(n);
        si(m);
        memset(idx, -1, sizeof idx);

        for(int i=0; i<n; i++)
        {
            si(a);
            val[i]=a;
            rnk[i]=1;
            par[i]=i;

            if(idx[a]== -1)
            {
                idx[a] = i;
            }
            else
            {
                Union(i,idx[a]);
                idx[a] = Find(i);
            }

        }

        printf("Case %d:\n",Case);

        while(m--)
        {
            si(a);

            if(a==1)
            {
                si(b);
                si(c);
                if(b==c || idx[b]==-1)
                {
                    continue ;
                }

                if(idx[c]==-1)
                {
                    idx[c] = idx[b];
                    val[idx[c]]=c;
                    idx[b]=-1;
                }
                else
                {
                    Union(idx[b],idx[c]);
                    idx[c] = Find(idx[c]);
                    val[idx[c]] = c;
                    idx[b]=-1;
                }

            }
            else
            {
                si(b);
                b--;

                printf("%d\n",val[Find(b)]);
            }
        }
    }


}

/*

1
10 100
1 2 3 4 5 1 2 3 100 200

2 1
1 1 100
2 6

*/

