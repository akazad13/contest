#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define pi pair<int,int>
#define mp(a,b) make_pair(a,b)

#define Clear(a,b) memset(a,b,sizeof(a))

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

#define MAX 100010

struct Node
{
    lld prop,sum;
};

Node tree[3*MAX+10];
int arr[MAX+10];

void build(int node, int start, int eend)
{
    if(start==eend)
    {
        tree[node].sum=0;
        tree[node].prop=-1;
        return ;
    }

    int mid = (start+eend)>>1;

    int nleft = node<<1;

    build(nleft,start,mid);
    build(nleft+1,mid+1,eend);

    tree[node].sum = tree[nleft].sum+tree[nleft+1].sum;
}


void lazy_update(int node, int start, int eend,int x)
{
    tree[node].prop = x;
    tree[node].sum = (eend-start+1)*x;
}

void node_update(int node, int start, int eend)
{
    int mid = (start+eend)>>1;
    int nleft = node<<1;
    int nright = nleft+1;

    tree[nleft].prop = tree[nright].prop = tree[node].prop;

    tree[nleft].sum = (mid-start+1)*tree[nleft].prop;
    tree[nright].sum = (eend-mid)*tree[nright].prop;

    tree[node].prop=-1;
}

void update(int node, int start, int eend, int left, int right, int x)
{
    if(start==left && eend==right)
    {
        lazy_update(node,start,eend,x);
        return ;
    }

    if(tree[node].prop!=-1)
    {
        node_update(node,start,eend);
    }

    int mid = (start+eend)>>1;

    int nleft = node<<1;

    if(right<=mid)
    {
        update(nleft,start,mid,left,right,x);
    }
    else if(left>mid)
    {
        update(nleft+1,mid+1,eend,left,right,x);
    }
    else
    {
        update(nleft,start,mid,left,mid,x);
        update(nleft+1,mid+1,eend,mid+1,right,x);
    }

    tree[node].sum = tree[nleft].sum+tree[nleft+1].sum;
}

lld query(int node, int start, int eend, int left,int right)
{
    if(start==left && eend==right)
    {
        return tree[node].sum;
    }

    if(tree[node].prop!=-1)
    {
        node_update(node,start,eend);
    }

    int mid = (start+eend)>>1;

    int nleft = node<<1;

    lld res=0;

    if(right<=mid)
    {
        res+=query(nleft,start,mid,left,right);
    }
    else if(left>mid)
    {
        res+=query(nleft+1,mid+1,eend,left,right);
    }
    else
    {
        res+=query(nleft,start,mid,left,mid);
        res+=query(nleft+1,mid+1,eend,mid+1,right);
    }

    tree[node].sum = tree[nleft].sum+tree[nleft+1].sum;

    return res;
}

int main()
{
    //freopen("input.txt","r",stdin);

    int test,i,j,Case,n,q,a,b,c,d;

    read(test);
    rep(Case,1,test+1)
    {


        rep(i,0,3*MAX+5)
        {
            tree[i].sum=0;
            tree[i].prop=0;
        }

        read(n); read(q);

        //rep(i,1,n+1)
        //{
          //  read(arr[i]);
        //}
        build(1,1,n);

        printf("Case %d:\n",Case);

        rep(i,1,q+1)
        {
            read(a);

            if(a==1)
            {
                read(b); read(c); read(d);
                b++; c++;
                update(1,1,n,b,c,d);
            }
            else
            {

                read(b); read(c);
                b++; c++;

                lld ret = query(1,1,n,b,c);
                //cout<<ret<<endl;

                lld diff = c-b+1;

                lld GCD = __gcd(ret,diff);

                ret/=GCD;
                diff/=GCD;

                if(diff==1)
                {
                    printf("%lld\n",ret);
                }
                else
                    printf("%lld/%lld\n",ret,diff);

            }
        }
    }

    return 0;
}




