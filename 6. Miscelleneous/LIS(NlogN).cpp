int lis(int n)
{
	int tail[n];

	tail[0] = a[0];
	int length = 1;

	for(int i = 1; i < n; i++) {
		if(a[i] > tail[length-1]) { //strictly greater
			tail[length++] = a[i];
		}
		else {
			auto it = lower_bound(tail, tail+length, a[i]);
			*it = a[i];
		}
	}

	return length;
}
