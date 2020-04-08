//mo's algorithm
class query {
public:
	ll l, r, indx;

	query() {}
	query(ll l, ll r, ll indx) : l(l), r(r), indx(indx) {}

	bool operator < (query x) {
		ll xbno = l/bsz, ybno = x.l/bsz;
		if(xbno == ybno) return (r<x.r);
		return (xbno < ybno);
	}
};

ll res[MX], freq[MX], ans;
vector <query> queries;

void add(ll p);//put something
void rem(ll p);//put something

void solve(ll n, ll m)
{
	ll l = 0, r = -1, ql, qr;
	ans = 0;

	bsz = ceil(sqrt(n));
    sort(queries.begin(), queries.end());

	for(ll i = 0; i < m; i++) {
		ql = queries[i].l, qr = queries[i].r;

        while(l > ql) add(--l);
        while(r < qr) add(++r);
        while(l < ql) rem(l++);
        while(r > qr) rem(r--);

        res[queries[i].indx] = ans;
	}
}
