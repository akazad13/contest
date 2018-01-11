#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define ll long long int

#define pb push_back
#define pi pair<int,int>
#define mp(a,b) make_pair(a,b)
#define eps 1e-9
#define PI 2.0*acos(0.0) //#define PI acos(-1.0)
ll  MOD =  1000000007;
#define INF (1<<28)

#define Clear(a,b) memset(a,b,sizeof(a))
//istringstream is()

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

template <class T> inline T bigmod(T p,T e,T M){
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}

template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

template<typename T>inline T POW(T B,T P)
{
    if(P==0) return 1;
    if(P&1) return B*POW(B,P-1);
    else return SQR(POW(B,P/2));
}



/************************************************************************************/

#define Max 1000005

bool prime[Max+10];
ll minPF[Max+10];

void sieve()
{
  //generating prime table
    for(ll i=2;i<=Max;i+=2)
    {
        prime[i]=1;
        minPF[i]=2;
    }

    for(ll i=3;i<=Max;i+=2)
    {
        if(prime[i]==0)
        {
             // cout<<i<<endl;
            minPF[i]=i;
           // cout<<"ok"<<endl;
            for(ll j=i*i;j<=Max;j+=2*i)
            {
                prime[j]=1;
                minPF[j]=i;

            }
        }
    }
    prime[2]=0;
}

ll arr[Max+10]={0};
ll mInv[Max+10]={0};
ll times[Max+10]={0};

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    //ios_base::sync_with_stdio(false); cin.tie(0);
    sieve();

    ll n,q,x,ans=1;

    read(n); read(q);

    ll cur=-1;
    ll cnt=0;


    while(n>1)
    {
        if(cur!=minPF[n] && cnt>0)
        {
            times[cur]=cnt;
            arr[cur] = bigmod(cur,cnt+1,MOD);
            mInv[cur] = modinverse(cur-1,MOD);
            cnt=0;
            ans = (ans*(arr[cur]-1+MOD)%MOD)%MOD;
            ans = (ans*mInv[cur])%MOD;
        }
        cur = minPF[n];
        cnt++;
        n/=cur;
    }

    if(cnt>0)
    {

        times[cur]=cnt;
        arr[cur] = bigmod(cur,cnt+1,MOD);
        mInv[cur] = modinverse(cur-1,MOD);
        ans = (ans*(arr[cur]-1+MOD)%MOD)%MOD;
        ans = (ans*mInv[cur])%MOD;
        cnt=0;
    }

    while(q--)
    {
        read(x);

        cnt=0;

        while(x>1)
        {
            if(cur!=minPF[x] && cnt>0)
            {
                if(times[cur]==0)
                {
                    times[cur]=cnt;
                    arr[cur] = bigmod(cur,times[cur]+1,MOD);
                    mInv[cur] = modinverse(cur-1,MOD);
                    ans = (ans*(arr[cur]-1+MOD)%MOD)%MOD;
                    ans = (ans*mInv[cur])%MOD;
                }
                else
                {
                    ans = (ans*modinverse(arr[cur]-1,MOD))%MOD;
                    if(ans<0)
                        ans+=MOD;

                    times[cur]+=cnt;
                    arr[cur] = bigmod(cur,times[cur]+1,MOD);
                    ans = (ans*(arr[cur]-1+MOD)%MOD)%MOD;

                }
                cnt=0;
            }
            cur = minPF[x];
           // cout<<cur<<endl;
            cnt++;
            x/=cur;
           // cout<<cur<<" "<<x<<" "<<ans<<endl;
        }

        if(cnt>0)
        {

                if(times[cur]==0)
                {
                    times[cur]=cnt;
                    arr[cur] = bigmod(cur,times[cur]+1,MOD);
                    mInv[cur] = modinverse(cur-1,MOD);
                    ans = (ans*(arr[cur]-1+MOD)%MOD)%MOD;
                    ans = (ans*mInv[cur])%MOD;
                }
                else
                {
                    ans = (ans*modinverse(arr[cur]-1,MOD))%MOD;
                    if(ans<0)
                        ans+=MOD;

                 //   cout<<ans<<" "<<arr[cur]<<endl;

                    times[cur]+=cnt;
                    arr[cur] = bigmod(cur,times[cur]+1,MOD);
                    ans = (ans*(arr[cur]-1+MOD)%MOD)%MOD;
                }
                cnt=0;
        }


        printf("%lld\n",ans);

    }

    return 0;
}
