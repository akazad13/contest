#include<bits/stdc++.h>
using namespace std;
#define mx 100011
int arr[mx];
long long sieve_size;
bitset<10000010> bs;
typedef vector <int> vi;
typedef long long ll;
vi primes;


void sieve(ll upperbound)
{
     sieve_size = upperbound + 1;
     bs.set();
     bs[0] = bs[1] = 0;
     for (ll i = 2; i <= sieve_size; i++)
        if (bs[i])
        {
            for (ll j = i * i; j <= sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i);
        }
}


int isPrime(ll N)
{
     if (N <= sieve_size) return (int)bs[N]; // O(1) for small primes
     for (int i = 0; i < (int)primes.size(); i++)
     if (N % primes[i] == 0) return 0;
     return 1;
}

//**********************************************************************************

#define MAX 100010

struct Node
{
    int prop,sum;
};

Node tree[3*MAX+10], ptree[3*MAX+10];
int pp[MAX+10];

void build(int node, int start, int eend)
{
    if(start==eend)
    {
        tree[node].sum=arr[start];
        cout<<start<<" "<<node<<" "<<arr[start]<<endl;
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


int query(int node, int start, int eend, int left,int right)
{
   // cout<<start<<" "<<eend<<endl;
    if(start==left && eend==right)
    {
        cout<<start<<" "<<node<<endl;
        return tree[node].sum;

    }

    if(tree[node].prop!=-1)
    {
        node_update(node,start,eend);
    }

    int mid = (start+eend)>>1;

    int nleft = node<<1;

    ll res=0;

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

void build_p(int node, int start, int eend)
{
    if(start==eend)
    {
        ptree[node].sum=pp[start];
        ptree[node].prop=-1;
        return ;
    }

    int mid = (start+eend)>>1;

    int nleft = node<<1;

    build_p(nleft,start,mid);
    build_p(nleft+1,mid+1,eend);

    ptree[node].sum = ptree[nleft].sum+ptree[nleft+1].sum;
}

void lazy_update_p(int node, int start, int eend,int x)
{
    ptree[node].prop = x;
    ptree[node].sum = (eend-start+1)*x;
}

void node_update_p(int node, int start, int eend)
{
    int mid = (start+eend)>>1;
    int nleft = node<<1;
    int nright = nleft+1;

    ptree[nleft].prop = ptree[nright].prop = ptree[node].prop;

    ptree[nleft].sum = (mid-start+1)*ptree[nleft].prop;
    ptree[nright].sum = (eend-mid)*ptree[nright].prop;

    ptree[node].prop=-1;
}

void update_p(int node, int start, int eend, int left, int right, int x)
{
    if(start==left && eend==right)
    {
        lazy_update_p(node,start,eend,x);
        return ;
    }

    if(tree[node].prop!=-1)
    {
        node_update_p(node,start,eend);
    }

    int mid = (start+eend)>>1;

    int nleft = node<<1;

    if(right<=mid)
    {
        update_p(nleft,start,mid,left,right,x);
    }
    else if(left>mid)
    {
        update_p(nleft+1,mid+1,eend,left,right,x);
    }
    else
    {
        update_p(nleft,start,mid,left,mid,x);
        update_p(nleft+1,mid+1,eend,mid+1,right,x);
    }

    ptree[node].sum = ptree[nleft].sum+ptree[nleft+1].sum;
}



ll query_p(int node, int start, int eend, int left,int right)
{
    if(start==left && eend==right)
    {
        return ptree[node].sum;
    }

    if(tree[node].prop!=-1)
    {
        node_update_p(node,start,eend);
    }

    int mid = (start+eend)>>1;

    int nleft = node<<1;

    ll res=0;

    if(right<=mid)
    {
        res+=query_p(nleft,start,mid,left,right);
    }
    else if(left>mid)
    {
        res+=query_p(nleft+1,mid+1,eend,left,right);
    }
    else
    {
        res+=query_p(nleft,start,mid,left,mid);
        res+=query_p(nleft+1,mid+1,eend,mid+1,right);
    }

    ptree[node].sum = ptree[nleft].sum+ptree[nleft+1].sum;

    return res;
}

//***********************************************************************************

int main()
{
    sieve(10000000);

    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]<=10000000)
            pp[i]=isPrime(arr[i]);
    }

    for(int i=0;i<=3*MAX;i++)
    {
        tree[i].prop=0;
        tree[i].sum=0;
        ptree[i].prop=0;
        ptree[i].sum=0;
    }

    build(1,1,n);
    build_p(1,1,n);

    for(int i=1;i<=8;i++)
        cout<<tree[i].sum<<endl;

    while(q--)
    {
        int a,l,r;
        char c;
        scanf(" %c",&c);
        if(c=='Q')
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",query_p(1,1,n,l,r));
            //cout<<query1(1,1,n,l,r)<<endl;
        }
        else if(c=='A')
        {
            scanf("%d%d",&a,&l);
            int sum = query(1,1,n,l,l);
            cout<<sum<<endl;
            int x = sum+a;
            update(1,1,n,l,l,x);
            if(x<=10000000)
            {
                cout<<x<<endl;
                if(isPrime(x)==1)
                {
                    update_p(1,1,n,l,l,1);
                }
                else
                {
                    update_p(1,1,n,l,l,0);
                }
            }
        }
        else
        {
            scanf("%d%d%d",&a,&l,&r);
            update_p(1,1,n,l,r,isPrime(a));
            update(1,1,n,l,r,a);
        }
    }
    return 0;
}
