#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define mx 100010
#define ll long long int

ll tree[3*mx];
ll arr[mx+10];

void build(int node, int s, int e)
{
    if(s==e)
    {
        tree[node]=arr[s];
        return ;
    }
    int mid = (s+e)>>1;

    int l = node<<1;
    int r = l+1;

    build(l,s,mid);
    build(r,mid+1,e);

    tree[node]=max(tree[l],tree[r]);
}

ll query(int node, int s, int e, int st, int ed)
{
    if(e<st || s>ed)
        return (-1*INT_MAX);
    if(s>=st && e<=ed)
    {
        return tree[node];
    }
    int mid = (s+e)>>1;

    int l = node<<1;
    int r = l+1;

    return max(query(l,s,mid,st,ed),query(r,mid+1,e,st,ed));
}

void update(int node,int s,int e, int ind,ll x)
{
    if(e<ind || s>ind)
        return ;
    if(s>=ind && e<=ind)
    {
        tree[node]=x;
        return ;
    }

    int mid = (s+e)>>1;

    int l = node<<1;
    int r = l+1;

    update(l,s,mid,ind,x);
    update(r,mid+1,e,ind,x);
    tree[node]=max(tree[l],tree[r]);
}

int main()
{
    int n,qur,st,ed;
    scanf("%d",&n);


    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    build(1,1,n);
    scanf("%d",&qur);

    for(int i=0;i<qur;i++) //to find max
    {
        scanf("%d %d",&st,&ed);
        printf("%lld\n",query(1,1,n,st,ed));

    }
    return 0;

}



