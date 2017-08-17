#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define mx 50000

int tree[3*mx];
int arr[mx+10];
int ans;

void make_tree(int node, int start, int eend)
{
    if(start==eend)
    {
        tree[node]=arr[start];
       // cout<<tree[node]<<" "<<node<<endl;
        return ;
    }
    int mid = (start+eend)>>1;
    
    int l = node<<1;
    int r = l+1;

    make_tree(l,start,mid);
    make_tree(r,mid+1,eend);

    tree[node]=max(tree[l],tree[r]);

}

int query(int node, int start, int eend, int st, int ed)
{
    if(eend<st || start>ed)
        return max(ans,-1*INT_MAX);
    if(start>=st && eend<=ed)
    {
        ans=max(ans,tree[node]);
        return ans;
    }
    int mid = (start+eend)>>1;
    
    int l = node<<1;
    int r = l+1;

    query(l,start,mid,st,ed);
    query(r,mid+1,eend,st,ed);


}

void update(int node,int start,int eend, int index,int x) //TO update
{
    if(eend<index || start>index)
        return ;
    if(start>=index && eend<=index)
    {
        tree[node]=x;
        return ;
    }

    int mid = (start+eend)>>1;
    
    int l = node<<1;
    int r = l+1;
    
    update(l,start,mid,index,x);
    update(r,mid+1,eend,index,x);
    tree[node]=max(tree[l],tree[r]);

}

int main()
{
    //freopen("in.txt","r",stdin);
    int test,n,qur,st,ed;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    make_tree(1,1,n);
    scanf("%d",&qur);

    for(int i=0;i<qur;i++) //to find max
    {
        ans=-1*INT_MAX;
        scanf("%d %d",&st,&ed);
        printf("%d\n",query(1,1,n,st,ed));

    }
    return 0;

}



