#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
//#define read(a) scanf("%d",&a)
#define Lread(a) scanf("%lld",&a)
#define Uread(a) scanf("%llu",&a)
#define Dread(a) scanf("%lf",&a)
#define write(a) printf("%d\n",a)
#define Case(a) printf("Case %d: ",a)

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define pi pair<int,int>
#define mp(a,b) make_pair(a,b)

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

    lld suffixSum,prefixSum,sum,maxSum;
};

lld arr[Max+10];
Node tree[4*Max+10];

void tree_build(int node, int st, int eend)
{
    //cout<<st<<" "<<eend<<endl;
    if(st==eend)
    {
        //cout<<arr[st]<<endl;
        tree[node].suffixSum=arr[st];
        tree[node].prefixSum=arr[st];
        tree[node].sum=arr[st];
        tree[node].maxSum=arr[st];


        return ;
    }

    int mid = (st+eend)>>1;

    tree_build(node<<1,st,mid);
    tree_build((node<<1)+1,mid+1,eend);

    tree[node].prefixSum = max(tree[node<<1].prefixSum,tree[node<<1].sum+tree[(node<<1)+1].prefixSum);
    tree[node].suffixSum = max(tree[(node<<1)+1].suffixSum,tree[(node<<1)+1].sum+tree[node<<1].suffixSum);
    tree[node].sum = tree[node<<1].sum+tree[(node<<1)+1].sum;

    tree[node].maxSum = max(tree[node].prefixSum,max(tree[node].suffixSum,max(tree[node<<1].maxSum,max(tree[(node<<1)+1].maxSum,tree[node<<1].suffixSum+tree[(node<<1)+1].prefixSum))));


    return ;
}

void update(int node, int start, int eend, int ind)
{
    if(start>ind || eend<ind)
        return ;
    if(start==ind && eend==ind)
    {
        //cout<<arr[st]<<endl;
        tree[node].suffixSum=arr[ind];
        tree[node].prefixSum=arr[ind];
        tree[node].sum=arr[ind];
        tree[node].maxSum=arr[ind];
        return ;
    }

    int mid = (start+eend)>>1;

    update(node<<1,start,mid,ind);
    update((node<<1)+1,mid+1,eend,ind);

    tree[node].prefixSum = max(tree[node<<1].prefixSum,tree[node<<1].sum+tree[(node<<1)+1].prefixSum);
    tree[node].suffixSum = max(tree[(node<<1)+1].suffixSum,tree[(node<<1)+1].sum+tree[node<<1].suffixSum);
    tree[node].sum = tree[node<<1].sum+tree[(node<<1)+1].sum;

    tree[node].maxSum = max(tree[node].prefixSum,max(tree[node].suffixSum,max(tree[node<<1].maxSum,max(tree[(node<<1)+1].maxSum,tree[node<<1].suffixSum+tree[(node<<1)+1].prefixSum))));


    return ;
}


Node tree_query(int node , int start, int eend, int L, int R)
{
    //cout<<ans.a<<endl;

    Node result;
    result.sum = result.prefixSum = inf;
    result.maxSum = result.suffixSum= inf;
   // cout<<result.maxSum<<endl;
    if(eend<L || start>R)
        return result;
    if(start>=L && eend<=R)
    {
     // cout<<tree[node].maxSum<<endl;
        return tree[node];

    }

    int mid = (start+eend)>>1;

    Node t1 = tree_query(node<<1,start,mid,L,R);
    Node t2 = tree_query((node<<1)+1,mid+1,eend,L,R);

    //cout<<t1.maxSum<<" "<<t2.maxSum<<endl;

    result.sum = t1.sum+t2.sum;
    result.prefixSum = max(t1.prefixSum,t1.sum+t2.prefixSum);
    result.suffixSum = max(t2.suffixSum,t2.sum+t1.suffixSum);

    result.maxSum = max(result.prefixSum,max(result.suffixSum,max(t1.maxSum,max(t2.maxSum,t1.suffixSum+t2.prefixSum))));

    return result;
}

lld val[100010];

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
                tree[i].prefixSum=tree[i].suffixSum=tree[i].sum=tree[i].maxSum=0;
            }

             tree_build(1,1,n-1);

             int id,l,r,ind;
             lld x;

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




