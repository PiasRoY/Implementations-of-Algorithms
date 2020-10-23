//mo's algorithm
class query {
public:
	int l, r, indx;

	query() {}
	query(int l, int r, int indx) : l(l), r(r), indx(indx) {}

	bool operator < (query x) {
		int xbno = l/bsz, ybno = x.l/bsz;
		if(xbno != ybno) return (xbno<ybno);
		return (xbno&1)?(r<x.r):(r>x.r);
	}
};

int res[MX], freq[MX], ans;
vector <query> queries;

void add(int p);//put something
void rem(int p);//put something

void solve(int n, int m)
{
	int l = 0, r = -1, ql, qr;
	ans = 0;

	bsz = ceil(sqrt(n));
    sort(queries.begin(), queries.end());

	for(int i = 0; i < m; i++) {
		ql = queries[i].l, qr = queries[i].r;

        while(l > ql) add(--l);
        while(r < qr) add(++r);
        while(l < ql) rem(l++);
        while(r > qr) rem(r--);

        res[queries[i].indx] = ans;
	}
}

//alternative sorting ordering
inline int gilbertOrder(int x, int y, int pow, int rotate) //(l, r, 21, 0)
{
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int subSquareSize = int(1) << (2*pow - 2);
	int ans = seg * subSquareSize;
	int add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}
