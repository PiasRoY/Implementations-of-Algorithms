//segment tree 2d
#define MX 1003
int n, m;
int mat[MX][MX], tree[4*MX][4*MX]; //mat[n][m], 64MB memory needed for 1003*1003

void build_y(int vx, int lx, int rx, int vy, int ly, int ry)
{
    if(ly == ry) {
		if(lx == rx) tree[vx][vy] = mat[lx][ly];
		else tree[vx][vy] = tree[vx*2][vy] + tree[vx*2+1][vy];

		return;
    }

	int mid = (ly+ry) / 2;
	build_y(vx, lx, rx, vy*2, ly, mid);
	build_y(vx, lx, rx, vy*2+1, mid+1, ry);

	tree[vx][vy] = tree[vx][vy*2] + tree[vx][vy*2+1];
}

void build_x(int vx, int lx, int rx) //Total Build Complexity: O(N*M)
{
	if(lx == rx) {
		build_y(vx, lx, rx, 1, 1, m);
		return;
	}

	int mid = (lx+rx) / 2;
	build_x(vx*2, lx, mid);
	build_x(vx*2+1, mid+1, rx);

	build_y(vx, lx, rx, 1, 1, m);
}

int query_y(int vx, int vy, int Ly, int Ry, int ly, int ry)
{
	if(Ly > ry || Ry < ly) return 0;
	if(Ly >= ly && Ry <= ry) return tree[vx][vy];

	int mid = (Ly+Ry) / 2;
	int Lch = query_y(vx, vy*2, Ly, mid, ly, ry);
	int Rch = query_y(vx, vy*2+1, mid+1, Ry, ly, ry);

	return Lch + Rch;
}

int query_x(int vx, int Lx, int Rx, int lx, int rx, int ly, int ry) //Total Query Complexity: O(logN*logM)
{
	if(Lx > rx || Rx < lx) return 0;
	if(Lx >= lx && Rx <= rx)
		return query_y(vx, 1, 1, m, ly, ry);

    int mid = (Lx+Rx) / 2;
    int Lch = query_x(vx*2, Lx, mid, lx, rx, ly, ry);
    int Rch = query_x(vx*2+1, mid+1, Rx, lx, rx, ly, ry);

    return Lch + Rch;
}

void update_y(int vx, int Lx, int Rx, int vy, int Ly, int Ry, int ry, int val)
{
	if(Ly > ry || Ry < ry) return;
	if(Ly >= ry && Ry <= ry) {
		if(Lx == Rx) tree[vx][vy] = val;
		else tree[vx][vy] = tree[vx*2][vy] + tree[vx*2+1][vy];

		return;
	}

	int mid = (Ly+Ry) / 2;
	update_y(vx, Lx, Rx, vy*2, Ly, mid, ry, val);
	update_y(vx, Lx, Rx, vy*2+1, mid+1, Ry, ry, val);

	tree[vx][vy] = tree[vx][vy*2] + tree[vx][vy*2+1];
}

void update_x(int vx, int Lx, int Rx, int lx, int ry, int val) //Total Update Complexity: O(logN*logM)
{
	if(Lx > lx || Rx < lx) return;
	if(Lx >= lx && Rx <= lx) {
		update_y(vx, Lx, Rx, 1, 1, m, ry, val);
		return;
	}

    int mid = (Lx+Rx) / 2;
    update_x(vx*2, Lx, mid, lx, ry, val);
    update_x(vx*2+1, mid+1, Rx, lx, ry, val);

    update_y(vx, Lx, Rx, 1, 1, m, ry, val);
}
