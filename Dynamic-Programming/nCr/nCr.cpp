#include<iostream>
#include<bits/stdc++.h>

using namespace std;
long long int dp[1000][1000];
#define MOD 1000003
long long int  find_nCr(int n, int r)
{
    if(n==r)
        return 1;
    if(r==1)
        return n;
    if(n<r)
        return 0;
    if(dp[n][r]!=-1)
        return dp[n][r];
    dp[n][r]=(find_nCr(n-1,r)%MOD +find_nCr(n-1,r-1)%MOD)%MOD;
    return dp[n][r];
}

int main()
{
    int n,r;
    while(cin>>n>>r)
    {
        for(int i=0;i<1000;i++)
            for(int j=0;j<1000;j++)
                dp[i][j]=-1;
        cout<<find_nCr(n,r)<<endl;
    }

    return 0;
}
