#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 60010
#define ll long long int

struct pp
{
    ll x,y,len,val;

    pp(ll a, ll b, ll c, ll d)
    {
        x=a; y=b; len=c; val=d;
    }
};

ll tree[4*Max+10];
ll Line[4*Max+10];
vector<pp> vec;
vector<ll> y;

void update(int node,int start,int eend, ll st,ll en, ll val)
{
    if(y[eend]<=st || y[start]>=en)
        return ;

    int mid = (start+eend)>>1;
    int l = node<<1;
    int r = l+1;

    if(y[start]>=st && y[eend]<=en)
    {
        Line[node]+= val;
        if(Line[node])
        {
            tree[node]= y[eend]-y[start];
        }
        else
        {
            if(eend-start == 1)
                tree[node]=0;
            else
                tree[node]=tree[l]+tree[r];
        }

        return ;

    }

    update(l,start,mid,st,en,val);
    update(r,mid,eend,st,en,val);

    if (Line[node])
        tree[node] = y[eend] - y[start];
    else
        tree[node] = tree[l] + tree[r];

    return ;

}

bool cmp(pp a, pp b)
{
    if(a.x==b.x)
        return a.val > b.val;

    return a.x < b.x ;
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test,n;
    ll x,a,b,c,d;

    scanf("%d",&test);

    for(int Case=1;Case<=test;Case++)
    {
        for(int i=0;i<=4*Max;i++)
        {
            tree[i]=0;
            Line[i]=0;
        }

        vec.clear();
        y.clear();

        scanf("%d",&n);

        for(int i=0;i<n;i++)
        {
            scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
            vec.push_back(pp(a,b,d,1));
            vec.push_back(pp(c,b,d,-1));

            y.push_back(b);
            y.push_back(d);
        }

        n = vec.size();

        sort(y.begin(),y.end());
        y.resize(unique(y.begin(),y.end())-y.begin());

        int cnt = y.size();

        sort(vec.begin(),vec.end(),cmp);

        ll sum=0,lastX=0;
        ll now, curX;

        for(int i=0;i<n;i++)
        {
            curX = vec[i].x;
            now = curX - lastX;

            sum+= tree[1]*now;

            update(1,0,cnt-1,vec[i].y, vec[i].len,vec[i].val);
            lastX = curX;
        }

        printf("Case %d: %lld\n",Case,sum);

    }


    return 0;

}
