#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define mx 100010

struct Node
{
    long long int prop;
    long long int sum;
};

Node tree[3*mx+10];
long long int arr[mx+10];

void make_tree(int node, int start, int eend)
{
    if(start==eend)
    {
        tree[node].sum=arr[start];
        tree[node].prop=0;
       // cout<<tree[node]<<" "<<node<<endl;
        return ;
    }
    int mid = (start+eend)/2;

    make_tree(2*node,start,mid);
    make_tree(2*node+1,mid+1,eend);

    tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;

}

long long int query(int node, int start, int eend, int st, int ed, long long int car)
{
    if(eend<st || start>ed)
        return 0;
    if(start>=st && eend<=ed)
    {
        return tree[node].sum+(eend-start+1)*car;
    }
    int mid = (start+eend)/2;

    long long int p1 = query(2*node,start,mid,st,ed,car+tree[node].prop);
    long long int p2 = query(2*node+1,mid+1,eend,st,ed,car+tree[node].prop);

    return p1+p2;

}

int m;

void update(int node,int start,int eend, int st,int en,long long int x)
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

    int mid = (start+eend)/2;
    update(2*node,start,mid,st,en,x);
    update(2*node+1,mid+1,eend,st,en,x);
    tree[node].sum=tree[node*2].sum+tree[node*2+1].sum +tree[node].prop*(eend-start+1);

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
         make_tree(1,1,n);

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
