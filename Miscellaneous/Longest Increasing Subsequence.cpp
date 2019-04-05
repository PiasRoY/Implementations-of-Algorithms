void lis(int n)
{
	int tail[n];

	tail[0] = a[0];
	int length = 1;

	for(int i = 0; i < n; i++) {
		if(a[i] > tail[length-1]) {
			tail[length++] = a[i];
			incr[i] = length;
		}
		else {
			auto it = lower_bound(tail, tail+length, a[i]);
			*it = a[i];
			incr[i] = it-tail+1;
		}
	}
}