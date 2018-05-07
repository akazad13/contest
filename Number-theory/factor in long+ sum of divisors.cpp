// all number must be less than max

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define Max 1000005
ll  MOD =  1000000007;

bool prime[Max+10];
ll minPF[Max+10];

void sieve()
{
    for(ll i=2;i<=Max;i+=2)
    {
        prime[i]=1;
        minPF[i]=2;
    }

    for(ll i=3;i<=Max;i+=2)
    {
        if(prime[i]==0)
        {
            minPF[i]=i;
            for(ll j=i*i;j<=Max;j+=2*i)
            {
                prime[j]=1;
                minPF[j]=i;
            }
        }
    }
    prime[2]=0;
}

template <class T> inline T bigmod(T p,T e,T M){
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}

template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

int main()
{
    sieve();

    ll n,ans=1,p,q;

    scanf("%lld",&n);

    ll cur=-1;
    ll cnt=0;

    while(n>1)
    {
        if(cur!=minPF[n] && cnt>0)
        {
            p = bigmod(cur,cnt+1,MOD);
            q = modinverse(cur-1,MOD);
            cnt=0;
            ans = (ans*(p-1+MOD)%MOD)%MOD;
            ans = (ans*q)%MOD;
        }
        cur = minPF[n];
        cnt++;
        n/=cur;
    }

    if(cnt>0)
    {
        p = bigmod(cur,cnt+1,MOD);
        q = modinverse(cur-1,MOD);
        ans = (ans*(p-1+MOD)%MOD)%MOD;
        ans = (ans*q)%MOD;
        cnt=0;
    }
    printf("%lld\n",ans);

    return 0;
}
