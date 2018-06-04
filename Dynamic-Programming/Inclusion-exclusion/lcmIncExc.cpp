#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long int
ll arr[12];
ll tow[101];
int n,m;
bool isOdd;

ll dp[1<<12];


ll solve(ll mask)
{
    ll lcm = 1;

    ll m = mask;

    for(int i=0;i<n;i++)
    {
        if(dp[mask]!=-1)
        {
            lcm = ((lcm*dp[mask])/__gcd(lcm,dp[mask]));
            break ;
        }
        if(mask&(1<<i))
        {
            lcm = ((lcm*arr[i])/__gcd(lcm,arr[i]));
            mask^=(1<<i);
        }


    }

    for(int i=0;i<n;i++)
    {

        if(m&(1<<i))
        {
            isOdd^=1;
        }
    }
    dp[m] = lcm;
    return lcm;
}

ll Get[4200];

int main()
{
    int test;

    scanf("%d",&test);

    for(int Case=1;Case<=test;Case++)
    {
        scanf("%d %d",&m,&n);

        for(int i=0;i<m;i++)
            scanf("%lld",&tow[i]);

        for(int i=0;i<n;i++)
            scanf("%lld",&arr[i]);



        int limit = 1<<n;

        for(int i=1;i<limit;i++)
            dp[i]=-1;

        dp[0]=1;

        int cnt=0;
        ll ret;

        for(int i=1;i<limit;i++)
        {
            isOdd = false;
            ret = solve(i);

            if(isOdd)
                Get[cnt++]=ret;
            else
                Get[cnt++]=-1*ret;
        }

        ll ans;
        ret=0;

        for(int i=0;i<m;i++)
        {
            ans = 0;
            for(int j=0;j<cnt;j++)
            {
                ans += (tow[i]/Get[j]);
            }

            ret^=(ans+1);  // for 0
        }

         printf("Case %d: ",Case);

        if(ret)
            printf("Alice\n");
        else
            printf("Bob\n");


    }

    return 0;
}

