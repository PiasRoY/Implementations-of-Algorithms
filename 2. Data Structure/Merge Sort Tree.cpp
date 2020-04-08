//Merge Sort Tree
#define MX 102
int arr[MX];
vector <int> tree[5*MX];

void build(int pos, int tl, int tr)
{
	if(tl == tr)
	{
		tree[pos].pb(arr[tl]);
		return ;
	}

	int mid = (tl+tr)/2;
	build(2*pos, tl, mid);
	build(2*pos+1, mid+1, tr);
	merge(tree[2*pos].begin(), tree[pos*2].end(), tree[2*pos+1].begin(), tree[2*pos+1].end(), back_inserter(tree[pos]));
}

int query(int pos, int tl, int tr, int l, int r, int k)
{
	if(tl > r || tr < l) return 0;
	if(tl >= l && tr <= r)
	{
		//Binary search over the current sorted vector to find elements smaller than K or equal to K
 		return upper_bound(tree[pos].begin(), tree[pos].end(), k) - tree[pos].begin();
	}

	int mid = (tl+tr)/2;
	return query(2*pos, tl, mid, l, r, k) + query(2*pos+1, mid+1, tr, l, r, k);
}
