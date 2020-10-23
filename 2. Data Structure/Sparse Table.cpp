//sparse table, Complexity- built: O(NlogN), query: O(1);
#define MX 500
int n, spt[MX][log2(MX)], arr[MX];

void build()
{
	for(int i = 0; i < n; i++)
		spt[i][0] = i;

	for(int j = 1; (1 << j) <= n; j++) {
		for(int i = 0; (i + (1<<j) - 1) < n; i++) {
			if(arr[spt[i][j-1]] < arr[spt[i + (1<<(j-1))][j-1]])
				spt[i][j] = spt[i][j-1];
			else
				spt[i][j] = spt[i+(1<<(j-1))][j-1];
		}
	}
}

int query(int L, int R)
{
	int j = log2(R - L + 1);

	if(arr[spt[L][j]] < arr[spt[R-(1<<j)+1][j]]) return arr[spt[L][j]]; //return spt[L][j] for index
	else return arr[spt[R-(1<<j)+1][j]]; //same for it.
}

ll query(ll l, ll r) {
	ll sum = 0;
	for(ll j = log2(r-l+1); j >= 0; j--) {
		if(l+(1<<j)-1 <= r) {
			sum += sm[l][j];
			l += (1<<j);
		}
	}
	return sum;
}
