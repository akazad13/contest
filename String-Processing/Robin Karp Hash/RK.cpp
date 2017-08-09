#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long int
ll MOD=1000000007;
ll  prime=101;

template <class T> inline T bigmod(T p,T e,T M){
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}

char sub[1000010];
char text[1000010];
ll primeVal[1000010];
ll pp;


ll patternSearch()
{
    ll len1 = strlen(text);
    ll len2 = strlen(sub);


    ll Hsub = 0;
    ll Hstr = 0;

    ll temp;


    for (ll i = 0 ; i <len2;i++)
    {
        Hsub = (Hsub+sub[i]*primeVal[i])%MOD;
        Hstr = (Hstr+text[i]*primeVal[i])%MOD;
    }


    ll cnt=0;


    ll qq = primeVal[len2-1];

    for(int i=0;i<=len1-len2;i++)
    {
        if(Hsub == Hstr)
            cnt++;

        Hstr = Hstr - text[i];

        if(Hstr<0)
            Hstr+=MOD;

        Hstr = Hstr*pp;//newHash/prime;
        if(Hstr<0)
            Hstr+=MOD;

        Hstr = (Hstr+text[i+len2]*qq)%MOD;

    }

    return cnt;

}

int main()
{

    primeVal[0]=1;
    for(ll i=1;i<=1000000;i++)
    {
        primeVal[i] = (primeVal[i-1]*prime)%MOD;
    }

    pp = bigmod(prime,MOD-2,MOD);

    int test,cnt,len;

    scanf("%d", &test);
    char ch= getchar();

    for(int Case = 1; Case <=test; Case++)
    {
        gets(text);
        gets(sub);

        printf("Case %d: %d\n", Case,patternSearch());
    }
    return 0;
}


