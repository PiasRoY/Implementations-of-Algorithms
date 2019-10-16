//fenwick tree
#define MX 100005
int n, bit[MX]; //bit[n], bit is like cumulative array but contains partial sums.

int query(int indx)
{
	int sum = 0;
	for(indx = indx+1; indx > 0; indx -= indx&-indx)
		sum += bit[indx];

	return sum;
}

void update(int indx, int val)
{
	for(indx = indx+1; indx <= n; indx += indx&-indx)
		bit[indx] += val;
}
