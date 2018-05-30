
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll n;
ll arr[1000002];

ll minSwaps()
{
	pair<ll, ll> arrPos[n];
	for (int i = 0; i < n; i++)
	{
		arrPos[i].first = arr[i];
		arrPos[i].second = i;
	}
	sort(arrPos, arrPos + n);

	vector<bool> vis(n, false);

	// Initialize result
	ll ans = 0;

	// Traverse array elements
	for (int i = 0; i < n; i++)
	{
		if (vis[i] || arrPos[i].second == i)
			continue;

		// find out the number of node in
		// this cycle and add in ans
		ll cycle_size = 0;
		int j = i;
		while (!vis[j])
		{
			vis[j] = 1;

			j = arrPos[j].second;
			cycle_size++;
		}

		// Update answer by adding current cycle.
		ans += (cycle_size - 1);
	}

	// Return result
	return ans;
}

// Driver program to test the above function
int main()
{
	cin>>n;

	for(int i=0;i<n;i++)
        scanf("%lld",&arr[i]);

	ll ret =  minSwaps();

	return 0;
}
