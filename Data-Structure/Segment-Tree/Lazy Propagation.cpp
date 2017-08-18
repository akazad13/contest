#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define mx 100010
#define ll long long int

struct Node
{
    ll prop;
    ll sum;
};

Node tree[3*mx+10];
ll arr[mx+10];

void build(int node, int start, int eend)
{
    if(start==eend)
    {
        tree[node].sum=arr[start];
        tree[node].prop=0;
       // cout<<tree[node]<<" "<<node<<endl;
        return ;
    }
    int mid = (start+eend)>>1;
    int l = node<<1;
    int r = l+1;

    build(l,start,mid);
    build(r,mid+1,eend);

    tree[node].sum=tree[l].sum+tree[r].sum;
    return;
}

ll query(int node, int start, int eend, int st, int ed, long long int car)
{
    if(eend<st || start>ed)
        return 0;
    if(start>=st && eend<=ed)
    {
        return tree[node].sum+(eend-start+1)*car;
    }
    int mid = (start+eend)>>1;
    int l = node<<1;
    int r = l+1;

    ll p1 = query(l,start,mid,st,ed,car+tree[node].prop);
    ll p2 = query(r,mid+1,eend,st,ed,car+tree[node].prop);

    return p1+p2;

}

int m;

void update(int node,int start,int eend, int st,int en,ll x)
{
    if(eend<st || start>en)
        return ;
    if(start>=st && eend<=en)
    {
        //cout<<"t"<<tree[node]<<endl;
        tree[node].prop+=x;
        tree[node].sum+=(abs(start-eend)+1)*x;

        return ;
    }

    int mid = (start+eend)>>1;
    int l = node<<1;
    int r = l+1;
    
    update(l,start,mid,st,en,x);
    update(r,mid+1,eend,st,en,x);
    tree[node].sum=tree[l].sum+tree[r].sum +tree[node].prop*(eend-start+1);

}

int main()
{
    //freopen("in.txt","r",stdin);
    int test,n,qur,st,en,p;
    long long int x;

    cin>>test;

    for(int Case=1;Case<=test;Case++)
    {
        for(int i=0;i<=3*mx;i++)
        {
            tree[i].sum=0;
            tree[i].prop=0;
        }
        for(int i=0;i<mx;i++)
            arr[i]=0;
        scanf("%d %d",&n,&qur);
        build(1,1,n);

        printf("Case %d:\n",Case);
        for(int i=0;i<qur;i++)
        {
            scanf("%d",&p);
            if(p==0)
            {
                scanf("%d %d %lld",&st,&en,&x);
                st++;
                en++;
                update(1,1,n,st,en,x);
            }
            else
            {
                //ans=0;
                scanf("%d %d",&st,&en);
                st++;en++;
                printf("%lld\n",query(1,1,n,st,en,0));
            }
        }

    }


    return 0;

}
