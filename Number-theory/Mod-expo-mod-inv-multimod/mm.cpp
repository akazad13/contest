/*
    Author:-Sarthak Taneja
    CSE 2nd year,MNNIT Allahabad
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair< int,int > ii;
typedef vector< ii > vii;

#define sfd(x) scanf("%d",&x)
#define sfd2(x,y) scanf("%d%d",&x,&y)
#define sfs(x) scanf("%s",x)
#define sff(x) scanf("%lf",&x)
#define mod 1000000007
#define MAX 1000000
#define INF 1000000000
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define testcases scanf("%d",&t);while(t--)
#define ffor(a,b,c) for(a=b;a<c;a++)
#define rfor(a,b,c) for(a=b;a>=c;a--)
#define PI 3.1415926535897932

ll power(ll base, ll exp)
{
	if(exp == 0)
	return 1;
	ll r = power(base, exp/2);
	r=(r*r)%mod;
	if(exp&1)
		r=(r*base)%mod;
	return r;
}

long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

/**********************************************/

int main()
{
	int i,j,t;

	ll a,b,n,x;

	cin>>a>>b>>n>>x;

	ll ans = (power(a, n));//Mod expo

		ans =(ans + mulmod(b,n,mod))%mod; //multiply
		tmp = (tmp * power(a -1, mod-2))%mod;//Mod inverse

	return 0;
}
