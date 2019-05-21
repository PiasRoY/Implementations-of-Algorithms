//fenwick tree
#define MX 100005
int n, bit[MX]; //bit[n], bit is like cumulative array but contains partial sums.

int query(int x)
{
	int res = 0;
	for(x = x+1; x > 0; x -= x&-x)
		res += bit[x];

	return res;
}

void update(int x, int val)
{
	for(x = x+1; x <= n; x += x&-x)
		bit[x] += val;
}
