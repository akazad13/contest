#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector< pair< ll, ll> > vec;

ll ans[100010];
ll dp[18][2][(1<<10)];
ll cnt[1030], mx[1030]={-1};

string str;
int m;

ll cal(int id, int r, int mask)
{
    //cout<<id<<" "<<r<<" "<<mask<<endl;
    if(id<0)
    {
        if(mx[mask]==cnt[mask])
        {
            //cout<<mask<<" "<<cnt<<endl;
            return 1;
        }
        else
            return 0;
    }

    if(dp[id][r][mask]!=-1 && r==0)
        return dp[id][r][mask];
    int en=9;
    ll res=0;
    if(r==1)
        en = str[id]-'0';

    for(int i=0;i<en;i++)
    {
        if(mask==0 && i==0)
            res+= cal(id-1,0,mask);
        else
            res+= cal(id-1,0,(mask|(1<<i)));
    }
    res+= cal(id-1,r,(mask|(1<<en)));

    return dp[id][r][mask]=res;

}

int main()
{

    memset(dp,-1,sizeof dp);

    for(ll i=0;i<1030;i++)
    {
        for(ll j=0;j<10;j++)
        {
            if((i&(1<<j)))
            {
                mx[i] = max(mx[i],j);
                cnt[i]++;
            }
        }
    }

    ll t,n;
    char s[20];
    scanf("%lld",&t);

    for(ll C=1;C<=t;C++)
    {
        scanf(" %s",s);
        m = strlen(s);

        str.clear();

        for(int i=m-1;i>=0;i--)
        {
            str+=s[i];
        }

      //  cout<<str<<" "<<m<<endl;

        printf("%lld\n",cal(m-1,1,0));
    }

    return 0;
}
