//fenwick tree
#define MX 1003
int n, m, bit[MX][MX]; //bit[n][m]

/* for a specific rectangle:
   query(rx, ry) - query(lx-1, ry) - query(rx, ly-1) + query(lx-1, ly-1), where lx <= ly & rx <= ry */

int query(int x, int y) //Complexity: O(log(N) * log(M))
{
	int res = 0;

	for(x = x+1; x > 0; x -= x&-x) { //log(N)
		for(int py = y+1; py > 0; py -= py&-py) { //log(M)
			res += bit[x][py];
		}
	}

	return res;
}

void update(int x, int y, int val) //Complexity: O(log(N) * log(M))
{
	for(x = x+1; x <= n; x += x&-x) { //log(N)
		for(int py = y+1; py <= m; py += py&-py) { // log(M)
			bit[x][py] += val;
		}
	}
}
