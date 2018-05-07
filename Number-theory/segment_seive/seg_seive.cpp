#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define MAX 1000010
#define ll long long int
bool prime[MAX+10];

void seive()
{
    for(int i=4;i<=MAX;i+=2)
        prime[i]=1;
    int srt = sqrt(MAX);
    for(int i=3;i<=srt;i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=MAX;j+=2*i)
            {
                prime[j]=1;
            }
        }
    }
    prime[0]=prime[1]=1;


}

bool seg_seive[100010];

ll first(ll lo,ll i)
{
    if(lo%i==0)
            return max(lo,i*i);
    else
        return max(lo + (i-lo%i),i*i);
}


void segment_seive(ll a, ll b)
{
    CLEAR(seg_seive,0);
        if(a==1)
        {
            seg_seive[a]=1;
        }

        for(ll k=first(a,2);k>=a&&k<=b;k=k+2)
            seg_seive[k-a+1]=1;

        ll max1 = sqrt(b);
        for(ll j=3;j<=max1;j+=2)
        {
            if(prime[j]==0)
            {
                for(ll k=first(a,j);k>=a&&k<=b;k=k+j)
                    seg_seive[k-a+1]=1;
            }

        }
}

int main()
{
    seive();

    ll test, low,up,count;
    scanf("%lld",&test);

    for(int i=1;i<=test;i++)
    {
        scanf("%lld %lld",&low,&up);
        segment_seive(low,up);

        count=0;
        for(int j=low;j<=up;j++)
        {
            if(seg_seive[j-low+1]==0)
            {
                count++;
            }
        }
        printf("Case %d: %lld\n",i,count);
    }
    return 0;
}
