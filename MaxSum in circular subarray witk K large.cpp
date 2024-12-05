ll maxSum(vll &a , int k) {
	if(a.empty())
		return INT_MIN;
	ll ans = INT_MIN, sum = 0,s = 0;
	int n = a.size();
	for(int i = 0; i < n; i++){
		s += a[i];
		a.push_back(a[i]);
	}
	for(int i = 0; i < n; i++)
		a.push_back(a[i]);
	ll tt = k / n;
	k -= tt * n;
	if(k < n && tt > 0) {
		k += n;
		tt--;
	}
	s *= tt;
	for(int i = 0; i < 2 * n; i++) {
		sum = 0;
		for(int j = i; j < min(i + k, 3 * n); j++){
			sum += a[j];
			ans = max(ans , sum);
		}
	}
	
	ans = max(ans , ans + s);
	return ans;
}