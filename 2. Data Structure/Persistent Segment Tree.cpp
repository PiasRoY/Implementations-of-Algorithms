//Persistent Segment Tree
#define MX 100005
int arr[MX];

struct node {
	node *left, *right;
	int val;

	node (int a = 0, node *b = NULL, node *c = NULL) :
		val(a), left(b), right(c) {}

    void build(int L, int R) {
        if(L == R) {
            val = arr[L];
			return;
        }

        left = new node();
        right = new node();

        int mid = (L+R)/2;
        left -> build(L, mid);
        right-> build(mid+1, R);

        val = left -> val + right -> val;
    }

	node* update(int L, int R, int indx, int v) {
		if(L > indx || R < indx) return this;
		if(L == R) {
			node *ret = new node(val, left, right);
            ret -> val += v;
            return ret;
		}

        int mid = (L+R)/2;
		node *ret = new node();
        ret -> left = left -> update(L, mid, indx, v);
        ret -> right= right-> update(mid+1, R, indx, v);

        ret -> val = ret -> left -> val + ret -> right -> val;
        return ret;
	}

    int query(int L, int R, int l, int r) {
        if(L > r || R < l) return 0;
        if(L >= l && R <= r) return val;

		int mid = (L+R)/2;
		int Lch = left -> query(L, mid, l, r);
		int Rch = right-> query(mid+1, R, l, r);

		return Lch+Rch;
    }

} *root[100005]; //total different versions of ST

int main()
{
	arr[1] = 2, arr[2] = 7, arr[3] = 3, arr[4] = 5, arr[5] = 1;

	root[0] = new node();
	root[0] -> build(1, 5);
	root[1] = root[0] -> update(1, 5, 2, 2);
}
