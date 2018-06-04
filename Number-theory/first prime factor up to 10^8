// factor and divisor to find euler pi and sum of coprime

#define __STDC_LIMIT_MACROS
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define ll long long int
#define pb push_back
#define pl pair< ll, ll >
#define mp(a,b) make_pair(a,b)

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

bool prime[100010];
vector<int> plist;
int psize=0;

void sieve()
{
    int mx = 100010;
    for(int i=4;i<mx;i+=2)
        prime[i]=1;

    int sq = sqrt(mx);

    for(int i=3;i<=sq;i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<mx;j+=2*i)
            {
                prime[j]=1;
            }
        }
    }
    prime[1]=prime[0]=1;

    for(int i=2;i<mx;i++)
    {
        if(prime[i]==0)
        {
            plist.pb(i);
            psize++;
        }
    }

    return ;
}




// 9 log(n)^3

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

// trival divisor O( n^(1/4) )
const int multiplier[] = {1, 3, 5, 7, 11, 3*5, 3*7, 3*11, 5*7, 5*11, 7*11, 3*5*7, 3*5*11, 3*7*11, 5*7*11, 3*5*7*11};
#define nelems(x) (sizeof(x) / sizeof((x)[0]))
ll SQUFOF( ll N )
{
    ll D, Po, P, Pprev, Q, Qprev, q, b, r, s;
    ll L, B, i;
    s = (ll)(sqrtl(N)+0.5);
    if (s*s == N) return s;
    for (int k = 0; k < nelems(multiplier) && N <= UINT64_MAX/multiplier[k]; k++)
    {
        D = multiplier[k]*N;
        Po = Pprev = P = sqrtl(D);
        Qprev = 1;
        Q = D - Po*Po;
        L = 2 * sqrtl( 2*s );
        B = 3 * L;
        for (i = 2 ; i < B ; i++)
        {
            b = (ll)((Po + P)/Q);
            P = b*Q - P;
            q = Q;
            Q = Qprev + b*(Pprev - P);
            r = (ll)(sqrtl(Q)+0.5);
            if (!(i & 1) && r*r == Q) break;
            Qprev = q;
            Pprev = P;
        };
        if (i >= B) continue;
        b = (ll)((Po - P)/r);
        Pprev = P = b*r + P;
        Qprev = r;
        Q = (D - Pprev*Pprev)/Qprev;
        i = 0;
        do
        {
            b = (ll)((Po + P)/Q);
            Pprev = P;
            P = b*Q - P;
            q = Q;
            Q = Qprev + b*(Pprev - P);
            Qprev = q;
            i++;
        }
        while (P != Pprev);
        r = __gcd(N, Qprev);
        if (r != 1 && r != N) return r;
    }
    return 0;
}

vector< pl > factors;

void findfactor(ll n)
{
    ll cnt;
    for(int i=0;i<psize && plist[i]*plist[i]<=n;i++)
    {
        if(n%plist[i]==0)
        {
            cnt=0;
            while(n%plist[i]==0)
            {
                n/=plist[i];
                cnt++;
            }

            factors.pb(mp(plist[i],cnt));
        }
    }

   // cout<<n<<" "<<factors.size()<<endl;

    if(n!=1)
        factors.pb(mp(n,1));

    return ;
}

void findfactorbig(ll n)
{
    ll cnt;
    ll tmp = n;
    for(int i=0;i<psize && plist[i]*plist[i]*plist[i]<=tmp;i++)
    {
        if(n%plist[i]==0)
        {
            cnt=0;
            while(n%plist[i]==0)
            {
                n/=plist[i];
                cnt++;
            }

            factors.pb(mp(plist[i],cnt));
        }
    }

    if(n!=1)
    {
        ll sq = sqrt(n);
        if(isPrime(n))
        {
            factors.pb(mp(n,1));
        }
        else if(sq*sq==n)
        {
            factors.pb(mp(sq,2));
        }
        else
        {
            ll div = SQUFOF(n);
            factors.pb(mp(div,1));
            factors.pb(mp(n/div,1));
        }
    }

    return ;
}

ll res;
ll val;
ll t=0;
ll sz;

void find_all_pi(ll id, ll n, ll pi)
{
    // cout<<id<<" "<<n<<" "<<pi<<endl;
   // t++;
  //  assert(t <= 1e4);

    if(id>=sz)
    {
        if(n*pi==2*val)
        {
            res=n;
            return ;
        }
        else
            return;
    }

  //  cout<<n*pi<<" "<<2*val<<endl;

    if(n*pi==2ll*val)
    {
        res=n;
        return ;
    }

    ll s = factors[id].second;
    ll p = factors[id].first;

   // cout<<p<<" "<<s<<endl;

    ll v1=1;
    ll v2=0;

    for(ll i=0; i<= s ;i++)
    {
        find_all_pi(id+1,n,pi*(v1-v2));
        n*=p;
        v2=v1;
        v1*=p;
    }

    return ;
}


int main()
{
    sieve();
    int test,Case;

    read(test);
    rep(Case,1,test+1)
    {
        read(val);

        if(val==1)
        {
            printf("2\n");
            continue ;
        }

        factors.clear();

        if(val<=10000000000)
        {
            findfactor(val);
        }
        else
        {
            findfactorbig(val);
        }

        res = -1;
        t = 0;
        sz = factors.size();

        //cout<<sz<<endl;

        find_all_pi(0,1,1);


        printf("%lld\n",res);
    }

    return 0;
}
