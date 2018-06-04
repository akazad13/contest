#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 142857

ll mod = mx;

/*ll pas[mx][mx];

ll nCr(ll n, ll r)
{
    if(n==r || r==0)
    {
        return 1;
    }

    if(pas[n][r]!=-1)
        return pas[n][r];


    pas[n][r] = (nCr(n-1,r)+nCr(n-1,r-1))%mod;

    return pas[n][r];
}*/

// save space
ll dp[mx];
ll nCrSave(ll n, ll r)
{
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;

    for (ll i = 1; i <= n; i++)
    {

        for (ll j = min(i, r); j > 0; j--)

            // nCj = (n-1)Cj + (n-1)C(j-1);
            dp[j] = (dp[j] + dp[j-1])%mod;
    }
    return dp[r];
}

// locus for mod < 10000  .. // p^2 + logp(n)
ll nCrLucas(ll n, ll r)
{
   if (r==0)
      return 1;

   // Compute last digits of n and r in base p
   ll ni = n%mod, ri = r%mod;

   return (nCrLucas(n/mod, r/mod) * // Last digits of n and r
           nCrSave(ni, ri)) % mod;  // Remaining digits
}


/* no mod
ll combi(int n,int k)
{
    ll ans=1;
    k=k>n-k?n-k:k;
    int j=1;
    for(;j<=k;j++,n--)
    {
        if(n%j==0)
        {
            ans*=n/j;
        }else
        if(ans%j==0)
        {
            ans=ans/j*n;
        }else
        {
            ans=(ans*n)/j;
        }
    }
    return ans;
} */


// Driver program
int main()
{
   // memset(pas, -1, sizeof(pas));

   int t;
    ll n,m;

    scanf("%d",&t);

    for(int i=0;i<t;i++)
    {
        scanf("%lld %lld",&n,&m);
        printf("%lld\n",nCrLucas(n,m));

    }

    return 0;
}
