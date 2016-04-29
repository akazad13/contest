#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int noOfCoin, coin[100],make;
    bool dp[100][100];
    memset(dp,0,sizeof(dp));
    cin>>noOfCoin>>make;
    for(int i=1;i<=noOfCoin;i++)
    {
        cin>>coin[i];
    }

    dp[0][0]=true;

    for(int i=1;i<=noOfCoin;i++)
    {
        for(int j=0;j<=make;j++)
        {
            //if(j==0)
             //   dp[i][j]=true;
            if(j<coin[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]|=(dp[i-1][j]|dp[i-1][j-coin[i]]);
        }
    }


    for(int i=0;i<=noOfCoin;i++)
    {
        for(int j=0;j<=make;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }



    return 0;
}
