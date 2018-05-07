#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll long long int


#define Clear(a,b) memset(a,b,sizeof(a))

#define Max 100010

template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

#define inf  -1000000000000000;

struct Node{

    ll sufSum,preSum,sum,maxSum;
};

ll arr[Max+10];
Node tree[4*Max+10];

void tree_build(int node, int s, int e)
{
    if(s==e)
    {
        tree[node].sufSum=arr[s];
        tree[node].preSum=arr[s];
        tree[node].sum=arr[s];
        tree[node].maxSum=arr[s];
        return ;
    }
    int mid = (s+e)>>1;
    int l = node<<1;
    int r = l+1;

    tree_build(l,s,mid);
    tree_build((l)+1,mid+1,e);

    tree[node].preSum = max(tree[l].preSum,tree[l].sum+tree[r].preSum);
    tree[node].sufSum = max(tree[r].sufSum,tree[r].sum+tree[l].sufSum);
    tree[node].sum = tree[l].sum+tree[r].sum;

    tree[node].maxSum = max(tree[node].preSum,max(tree[node].sufSum,max(tree[l].maxSum,max(tree[r].maxSum,tree[l].sufSum+tree[r].preSum))));
    return ;
}

void update(int node, int s, int e, int ind)
{
    if(s>ind || e<ind)
        return ;
    if(s==ind && e==ind)
    {
        tree[node].sufSum=arr[ind];
        tree[node].preSum=arr[ind];
        tree[node].sum=arr[ind];
        tree[node].maxSum=arr[ind];
        return ;
    }

    int mid = (s+e)>>1;
    int l = node<<1;
    int r = l+1;

    update(l,s,mid,ind);
    update(r,mid+1,e,ind);

    tree[node].preSum = max(tree[l].preSum,tree[l].sum+tree[r].preSum);
    tree[node].sufSum = max(tree[r].sufSum,tree[r].sum+tree[l].sufSum);
    tree[node].sum = tree[l].sum+tree[r].sum;

    tree[node].maxSum = max(tree[node].preSum,max(tree[node].sufSum,max(tree[l].maxSum,max(tree[r].maxSum,tree[l].sufSum+tree[r].preSum))));
    return ;
}


Node tree_query(int node , int s, int e, int L, int R)
{
    Node result;
    result.sum = result.preSum = inf;
    result.maxSum = result.sufSum= inf;

    if(e<L || s>R)
        return result;
    if(s>=L && e<=R)
    {
        return tree[node];
    }

    int mid = (s+e)>>1;
    int l = node<<1;
    int r = l+1;

    Node t1 = tree_query(l,s,mid,L,R);
    Node t2 = tree_query(r,mid+1,e,L,R);

    result.sum = t1.sum+t2.sum;
    result.preSum = max(t1.preSum,t1.sum+t2.preSum);
    result.sufSum = max(t2.sufSum,t2.sum+t1.sufSum);

    result.maxSum = max(result.preSum,max(result.sufSum,max(t1.maxSum,max(t2.maxSum,t1.sufSum+t2.preSum))));

    return result;
}


ll val[100010];

int main()
{
    //freopen("input.txt","r",stdin);


        int test,i,j,Case,n,q;
        read(test);

        for(Case=1;Case<=test;Case++)
        {
            read(n); read(q);

            for(int i=1;i<=n;i++)
            {
                read(val[i]);
            }

            if(n==1)
            {
                printf("Case %d:\n",Case);
                while(q--)
                {
                    read(n);
                    if(n==1)
                    {
                        read(n); read(n);

                    }
                    else
                    {
                        read(n); read(n);
                        printf("0\n");
                    }
                }
                continue ;
            }

            for(int i=2;i<=n;i++)
            {
                arr[i-1] = val[i]-val[i-1];
            }

            for(int i=0;i<4*n;i++)
            {
                tree[i].preSum=tree[i].sufSum=tree[i].sum=tree[i].maxSum=0;
            }

             tree_build(1,1,n-1);

             int id,l,r,ind;
             ll x;

             printf("Case %d:\n",Case);

             while(q--)
             {
                 read(id);

                 if(id==1)
                 {
                    read(ind); read(x);
                    val[ind] = x;

                    if(ind!=1)
                    {
                        arr[ind-1] = val[ind] - val[ind-1];
                        update(1,1,n-1,ind-1);
                    }
                    if(ind!=n)
                    {
                        arr[ind] = val[ind+1]-val[ind];
                        update(1,1,n-1,ind);
                    }
                 }
                 else
                 {
                    read(l); read(r);

                    if(l==r)
                    {
                        printf("0\n");
                        continue ;
                    }

                    Node  ans = tree_query(1,1,n-1,l,r-1);

                    if(ans.maxSum<=0)
                        printf("0\n");
                    else
                        printf("%lld\n",ans.maxSum);
                 }
             }

        }
    return 0;
}
