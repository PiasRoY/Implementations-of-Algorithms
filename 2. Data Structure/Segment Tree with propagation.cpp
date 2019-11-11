//Segment Tree
#define MX 100
int arr[MX];
int tree[MX*4], prop[MX*4];

void build(int pos, int l, int r) //Complexity: O(N)
{
    if(l == r) {
        tree[pos] = arr[l];
        return;
    }

    int mid = (l+r)/2;
    build(pos*2, l, mid);
    build(pos*2+1, mid+1, r);

    tree[pos] = tree[pos*2] + tree[pos*2+1];
}

void push_down(int pos, int L, int R) 
{
    tree[pos] += (R-L+1)*prop[pos];

    if(L != R) {
        prop[pos*2] += prop[pos];
        prop[pos*2+1] += prop[pos];
    }

    prop[pos] = 0;
}

void range_update(int pos, int L, int R, int l, int r, int x) //Complexity: O(logN)
{
    if(prop[pos]) push_down(pos, L, R);

    if(L > r || R < l) return;

    if(l <= L && R <= r) {
        tree[pos] += (R-L+1)*x;

        if(L != R) {
            prop[pos*2] += x;
            prop[pos*2+1] += x;
        }

        return;
    }

    int mid = (L+R)/2;
    range_update(pos*2, L, mid, l, r, x);
    range_update(pos*2+1, mid+1, R, l, r, x);

    tree[pos] = tree[pos*2] + tree[pos*2+1];
}

int query(int pos, int L, int R, int l, int r) //Complexity: O(logN)
{
    if(prop[pos]) push_down(pos, L, R);

    if(L > r || R < l) return 0;
    if(l <= L && R <= r) return tree[pos];

    int mid = (L+R)/2;
    int Lch = query(pos*2, L, mid, l, r);
    int Rch = query(pos*2+1, mid+1, R, l, r);

    return Lch+Rch;
}
