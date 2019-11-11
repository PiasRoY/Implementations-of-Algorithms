//Merge Sort Tree
#define MX 102
int arr[MX];
vector <int> tree[5*MX];

void build(int pos, int L, int R)
{
	if(L == R)
	{
		tree[pos].pb(arr[L]);
		return ;
	}

	int mid = (L+R)/2;
	build(2*pos, L, mid);
	build(2*pos+1, mid+1, R);
	merge(tree[2*pos].begin(), tree[pos*2].end(), tree[2*pos+1].begin(), tree[2*pos+1].end(), back_inserter(tree[pos]));
}

int query(int pos, int L, int R, int l, int r, int k)
{
	if(L > r || R < l) return 0;
	if(L >= l && R <= r)
	{
		//Binary search over the current sorted vector to find elements smaller than K or equal to K
 		return upper_bound(tree[pos].begin(), tree[pos].end(), k) - tree[pos].begin();
	}

	int mid = (L+R)/2;
	return query(2*pos, L, mid, l, r, k) + query(2*pos+1, mid+1, R, l, r, k);
}
