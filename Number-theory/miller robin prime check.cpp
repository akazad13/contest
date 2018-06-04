#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define ll long long int

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

template <class T> inline T bigmul(T p,T e,T M){
    ll ret = 0;
    p = p%M;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret + p) % M;
        p = (p + p) % M;
    } return (T)ret%M;
}

template <class T> inline T bigmod(T p,T e,T M){
    ll ret = 1;
    p = p%M;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = bigmul(ret, p, M);
        p = bigmul(p, p, M);
    } return (T)ret%M;
}

/******************************/


bool isPrime(ll n)
{
    ll d = n - 1;
    int s = 0;
    while (d % 2 == 0)
    {
        s++;
        d >>= 1;
    }
// It's guranteed that these values will work for any number smaller than 3*10**18 (3 and 18 zeros)
    ll a[9] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
    for(int i = 0; i < 9; i++)
    {
        bool comp = bigmod(a[i], d, n) != 1;
        if(comp) for(int j = 0; j < s; j++)
            {
                ll fp = bigmod(a[i], (1LL << (ll)j)*d, n);
                if (fp == n - 1)
                {
                    comp = false;
                    break;
                }
            }
        if(comp) return false;
    }
    return true;
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    //ios_base::sync_with_stdio(false); cin.tie(0);

    int test,Case;
    ll n,m;
    read(test);
    rep(Case,1,test+1)
    {
        cin>>n;
        cout<<isPrime(n)<<endl;
    }

    return 0;
}
