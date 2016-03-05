#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int


#define read(a) scanf("%d",&a)
#define Lread(a) scanf("%lld",&a)
#define Uread(a) scanf("%llu",&a)
#define Dread(a) scanf("%lf",&a)
#define write(a) printf("%d\n",a)
#define Case(a) printf("Case %d: ",a)

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define PR pair<int,int>
#define MP(a,b) make_pair(a,b)

#define Clear(a,b) memset(a,b,sizeof(a))
#define MOD 1000000007


VL MatrixMul(VL Mat1, VL Mat2) //2*2 mat
{
    VL res;
    res.pb(((Mat1[0]*Mat2[0])%MOD+(Mat1[1]*Mat2[2])%MOD)%MOD);
    res.pb(((Mat1[0]*Mat2[1])%MOD+(Mat1[1]*Mat2[3])%MOD)%MOD);
    res.pb(((Mat1[2]*Mat2[0])%MOD+(Mat1[3]*Mat2[2])%MOD)%MOD);
    res.pb(((Mat1[2]*Mat2[1])%MOD+(Mat1[3]*Mat2[3])%MOD)%MOD);

    return res;

}

VL Exponential(VL Mat,int power)
{
    if(power==1)
        return Mat;
    if(power%2==1)
    {
        return MatrixMul(Mat,Exponential(Mat,power-1));
    }

    VL M = Exponential(Mat,power/2);

    return MatrixMul(M,M);
}

int main()
{
   // freopen("input.txt","r",stdin);

    VL A,B;
    int test,i,j;
    lld a,b,n;
    read(test);
    for(int Case=1;Case<=test;Case++)
    {
        scanf("%lld %lld %lld",&a,&b,&n);
        A.clear();
        B.clear();
        A.pb(1);A.pb(1);A.pb(1);A.pb(0);
        B = Exponential(A,n);
        lld res = ((B[2]*b)%MOD + (B[3]*a)%MOD)%MOD;
        printf("%lld\n",res);

    }

    return 0;
}

