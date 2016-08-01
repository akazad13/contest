#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    int rem;
    while(b!=0)
    {
        rem=a%b;
        a=b;
        b=rem;
    }

    return a;
}

int main()
{
   int a,b;

   while(scanf("%d %d",&a,&b)==2)
   {
       int res = gcd(a,b);
       printf("GCD = %d\n",res);
   }

    return 0;
}

