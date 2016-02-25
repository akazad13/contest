#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define lld long long int

int main()
{
    int n;
    lld arr[100010];
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    lld cur_max_product = arr[0];
    lld pre_min_product = arr[0];
    lld pre_max_product = arr[0];
    lld cur_min_product = arr[0];
    lld ans = arr[0];

    for(int i=1;i<n;i++)
    {
        cur_max_product = max(pre_max_product*arr[i],max(pre_min_product,arr[i]));
        cur_min_product = min(pre_max_product*arr[i],min(pre_min_product,arr[i]));
        ans = max(ans,cur_max_product);
        pre_max_product = cur_max_product;
        pre_min_product = cur_min_product;
    }

    cout<<ans<<endl;

    return 0;
}
