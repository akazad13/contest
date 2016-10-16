#include <iostream>
#include <stdio.h>
#include <math.h>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long int

#define rn 2  //number of rows in matrix
#define cn 2  //number of column in matrix



struct matrix
{
    ll mat[rn][cn];

    matrix() //initializing to 0
    {
        for (int i = 0; i < rn; i++)
            for (int j = 0; j < cn; j++)
                mat[i][j] = 0;
    }
} base, unit;

matrix mul(matrix A, matrix B)
{
    int i, j, k;
    ll s;

    matrix res;

    for (i = 0; i < rn; i++)
        for (j = 0; j < cn; j++)
        {
            s = 0;
            for (k = 0; k < rn; k++)
                s = (s + (A.mat[i][k]*B.mat[k][j]));
            res.mat[i][j] = s;
        }
    return res;
}

matrix expo(matrix b, ll p)
{
    if (p==1)
    {
        return b;
    }

    matrix x = expo(b, p/2);

    if (p%2 == 0)
    {
        return mul(x, x);
    }
    else
    {
        return mul(b, mul(x, x));
    }
}


int main()
{

	int test;
	ll a,b,n,p;

	scanf("%d",&test);


	for(int Case=1;Case<=test;Case++)
    {


		scanf("%llu %llu %llu",&a,&b,&n);

		base.mat[0][0] = a;
		base.mat[0][1] = -b;
		base.mat[1][0] = 1;
		base.mat[1][1] = 0;

		//cout<<mod<<endl;

		if(n == 0)
        {
			printf("Case %d: 2\n",Case);
			continue;
		}

		if(n==1)
        {
			printf("Case %d: %llu\n",Case,a);
			continue;
		}

		matrix res = expo(base,n-1);


		printf("Case %d: %llu\n",Case, ((res.mat[0][0]*a) + (res.mat[0][1] * 2)));
	}

    return 0;
}
