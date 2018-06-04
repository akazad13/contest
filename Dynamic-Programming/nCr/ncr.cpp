#include<bits/stdc++.h>

using namespace std;


#define mx 100010
#define ll long long

bool prime[mx];
vector<ll> primes;
int s;

void sieve()
{
    for(int i=4;i<mx;i+=2)
        prime[i]=1;

    int sq = sqrt(mx);

    for(int i=3;i<sq;i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<mx;j+=(2*i))
                prime[j]=1;
        }
    }

    for(int i=2;i<mx;i++)
    {
        if(prime[i]==0)
        {
            primes.push_back(i);
        }
    }

    s = primes.size();
}

ll freq[mx];

ll cal(ll n, ll p)
{
    ll ans=0;

    ll k = p;

    while(p<=n)
    {
        ans+= (n/p);
        p*=k;
    }

    return ans;
}

template <class T> inline T bigmod(T p,T e,T M){
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret%M;
}

int main()
{
    sieve();

    int t,c;
    ll n,m,mod;

    scanf("%d",&t);

    for(int i=0;i<t;i++)
    {
        scanf("%lld %lld %lld",&n,&m,&mod);

        if(m>n)
        {
            printf("0\n");
            continue ;
        }

        memset(freq,0,sizeof(freq));

        for(int i=0;i<s && primes[i]<=n;i++)
        {
            freq[primes[i]] = cal(n,primes[i]);
          //  cout<<freq[primes[i]]<<" "<<primes[i]<<endl;

            freq[primes[i]] -= cal(m,primes[i]);

            freq[primes[i]] -= cal(n-m,primes[i]);
        }

        ll ans=1;

        for(int i=0;i<s;i++)
        {
            if(freq[primes[i]])
            {
                ans = (ans*bigmod(primes[i],freq[primes[i]],mod))%mod;
            }
        }

        printf("%lld\n",ans);
    }

    return 0;
}
