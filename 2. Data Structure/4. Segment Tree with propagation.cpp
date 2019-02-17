#define MX 100
int arr[MX];
int tree[MX*4], prop[MX*4];

void build(int pos, int l, int r)
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

void range_update(int pos, int l, int r, int L, int R, int x)
{
    if(prop[pos]) {
        tree[pos] += (r-l+1)*prop[pos];

        if(l != r) {
            prop[pos*2] += prop[pos];
            prop[pos*2+1] += prop[pos];
        }

        prop[pos] = 0;
    }

    if(l > R || r < L) return;

    if(l >= L && r <= R) {
        tree[pos] += (r-l+1)*x;

        if(l != r) {
            prop[pos*2] += x;
            prop[pos*2+1] += x;
        }

        return;
    }

    int mid = (l+r)/2;
    range_update(pos*2, l, mid, L, R, x);
    range_update(pos*2+1, mid+1, r, L, R, x);

    tree[pos] = tree[pos*2] + tree[pos*2+1];
}

int query(int pos, int l, int r, int L, int R)
{
    if(prop[pos]) {
        tree[pos] += (r-l+1)*prop[pos];

        if(l != r) {
            prop[pos*2] += prop[pos];
            prop[pos*2+1] += prop[pos];
        }

        prop[pos] = 0;
    }

    if(l > R || r < L) return 0;
    if(l >= L && r <= R) return tree[pos];

    int mid = (L+R)/2;
    int Lch = query(pos*2, l, mid, L, R);
    int Rch = query(pos*2+1, mid+1, r, L, R);

    return Lch+Rch;
}
