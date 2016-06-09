#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define read(a) scanf("%d",&a)
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

int arr[30010];
int Map[1000100];

struct node
{
    int L,R,ind;
};

node query[200002];
int res[200002];
int block;
int ans;

bool compare(node x, node y)
{
    // Different blocks, sort by block.
    if ((x.L/block) != (y.L/block))
        return (x.L/block) < (y.L/block);

    // Same block, sort by R value
    return (x.R < y.R);
}

void add(int pos)
{
    Map[arr[pos]]++;
    if(Map[arr[pos]]==1)
       ans++;

}

void Remove(int pos)
{
    Map[arr[pos]]--;
    if(Map[arr[pos]]==0)
       ans--;
}

void Mo(int n, int m)
{
    block = (int) sqrt(n);

    sort(query,query+m,compare);

    int curL=0;
    int curR=0;
    ans=0;
    int i;

    rep(i,0,m)
    {
        int L = query[i].L;
        int R = query[i].R;

        while(curL<L)
        {
            Remove(curL);
            curL++;
        }
        while(curL>L)
        {
            add(curL-1);
            curL--;
        }

        while(curR<=R)
        {
            add(curR);
            curR++;
        }
        while(curR>R+1)
        {
            Remove(curR-1);
            curR--;
        }

        res[query[i].ind] = ans;

        // printf("%d\n",ans);
    }

    rep(i,0,m)
        printf("%d\n",res[i]);
}


int main()
{
    //freopen("input.txt","r",stdin);

    int test,i,j,Case,n,m,p,q;
        Clear(Map,0);
        read(n);

        rep(i,0,n)
            read(arr[i]);
        read(m);
        rep(i,0,m)
        {

            read(p);
            read(q);
            query[i].L=p-1;
            query[i].R=q-1;
            query[i].ind=i;

        }

        Mo(n,m);



    return 0;
}

