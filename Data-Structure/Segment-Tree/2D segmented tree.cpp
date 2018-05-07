#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define Clear(a,b) memset(a,b,sizeof(a))

#define Max 505

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


int arr[Max][Max];
int tree[4*Max*Max+4];



void build(int node, int a1, int b1, int a2, int b2)
{
    if (a1 > a2 or b1 > b2)
        return ;
    if(a1==a2 and b1==b2)
    {
        tree[node] = arr[a1][b1];
        return ;
    }

    int mid1 = (a1+a2)/2;
    int mid2 = (b1+b2)/2;

    build(4*node-2,a1,b1,mid1,mid2);
    build(4*node-1,mid1+1,b1,a2,mid2);
    build(4*node+0,a1,mid2+1,mid1,b2);
    build(4*node+1,mid1+1,mid2+1,a2,b2);

    tree[node]=max(tree[4*node-2],max(tree[4*node-1],max(tree[4*node],tree[4*node+1])));

    return ;
}

int query(int node,int a1,int b1, int a2, int b2, int x1,int y1, int x2, int y2)
{
    if(a2<x1 || a1>x2 || y1>b2 || y2<b1 ||a1>a2 || b1>b2)
    {
        return 0;
    }
    if(x1 <= a1 and y1 <= b1 and a2 <= x2 and b2 <= y2)
    {
        return tree[node];
    }

    int ret=0;

    int mid1 = (a1+a2)/2;
    int mid2 = (b1+b2)/2;

    ret = max(ret,query(4*node-2,a1,b1,mid1,mid2,x1,y1,x2,y2));
    ret = max(ret,query(4*node-1,mid1+1,b1,a2,mid2,x1,y1,x2,y2));
    ret = max(ret,query(4*node+0,a1,mid2+1,mid1,b2,x1,y1,x2,y2));
    ret = max(ret,query(4*node+1,mid1+1,mid2+1,a2,b2,x1,y1,x2,y2));

    return ret;
}

int main()
{
    int test,i,j,Case,n,q,a1,b1,s;
    read(test);
    rep(Case,1,test+1)
    {
        read(n); read(q);

        rep(i,0,4*Max*Max)
            tree[i]=0;

        rep(i,1,n+1)
        {
            rep(j,1,n+1)
            {
                read(arr[i][j]);
            }
        }
        build(1,1,1,n,n);

        printf("Case %d:\n",Case);

        while(q--)
        {
            read(a1);
            read(b1);
            read(s);

            int ret = query(1,1,1,n,n,a1,b1,a1+s-1,b1+s-1);
            printf("%d\n",ret);
        }
    }
    return 0;
}
