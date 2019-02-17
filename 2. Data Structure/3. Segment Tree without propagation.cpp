//SegmentedTree
#define MX 1000
int arr[MX];
int tree[4*MX];

void build(int pos, int L, int R)
{
    if(L == R) {
        tree[pos] = arr[L];
        return;
    }

    int mid = (L+R)/2;
    build(pos*2, L, mid);
    build(pos*2+1, mid+1, R);

    tree[pos] = tree[pos*2] + tree[pos*2+1];
}

int query(int pos, int L, int R, int l, int r)
{
    if(l > R || r < L) return 0;
    if(L >= l && R <= r) return tree[pos];

    int mid = (L+R)/2;
    int Lsum = query(pos*2, L, mid, l, r);
    int Rsum = query(pos*2+1, mid+1, R, l, r);

    return Lsum + Rsum;
}

void update(int pos, int L, int R, int index, int new_value)
{
    if(index < L || index > R) return;
    if(L == R) {
        tree[pos] = new_value;
        return;
    }

    int mid = (L+R)/2;
    update(pos*2, L, mid, index, new_value);
    update(pos*2+1, mid+1, R, index, new_value);

    tree[pos] = tree[pos*2] + tree[pos*2+1];
}