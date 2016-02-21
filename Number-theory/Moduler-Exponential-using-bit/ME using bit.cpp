#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    unsigned int a,b;
    int res;
    int test;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%u %u",&a,&b);
        res=1;
        while(b)
        {
            if(b&1)
                res = (res*a)%10;
            b=b>>1;
            a = (a*a)%10;
        }
        printf("%d\n",res);
    }

    return 0;
}
