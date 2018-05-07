// C++ program to find maximum product subarray

ll max_product()
{
	ll max_fwd = INT_MIN, max_bkd = INT_MIN;

	// Initialize current product
	ll max_till_now = 1;

	for (int i=0; i<n; i++)
	{
		// if arr[i]==0, it is breaking condition
		// for contiguos subarray
		max_till_now = max_till_now*arr[i];
		if (max_till_now == 0)
		{
			max_till_now = 1;
			continue;
		}
		if (max_fwd < max_till_now)
			max_fwd = max_till_now;
	}

	max_till_now = 1;

	// iterating within backward direction in array
	for (int i=n-1; i>=0; i--)
	{
		max_till_now = max_till_now * arr[i];
		if (max_till_now == 0)
		{
			max_till_now = 1;
			continue;
		}

		// update max_bkd
		if (max_bkd < max_till_now)
			max_bkd = max_till_now;
	}

	// return max of max_fwd and max_bkd
	ll res = max(max_fwd, max_bkd);
	return max(res, 0);
}


