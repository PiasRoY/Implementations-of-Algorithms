//closest pair of points
#define MX 100005
#define pdd pair<double, double>

double min_dist;
pdd points[MX], t[MX];
pair<pdd, pdd> best_pair;

bool cmp_y(const pdd &a, const pdd &b) {
	return a.ss < b.ss;
}

void upd_ans(const pdd &a, const pdd &b)
{
    double dist = sqrt((a.ff-b.ff)*(a.ff-b.ff) + (a.ss-b.ss)*(a.ss-b.ss));

    if (dist + eps < min_dist) { //eps
        min_dist = dist;
        best_pair = mk(a, b);
    }
}

void rec(int l, int r)
{
	if(r-l <= 3) {
		for(int i = l; i <= r; ++i) {
            for(int j = i+1; j <= r; ++j) {
				upd_ans(points[i], points[j]);
            }
		}
		sort(points+l, points+r+1, cmp_y);
		return;
	}

	int mid = (l+r) >> 1;
	double midx = points[mid].ff;

    rec(l, mid);
    rec(mid+1, r);

    merge(points+l, points+mid+1, points+mid+1, points+r+1, t, cmp_y);
    copy(t, t+r-l+1, points+l);

    int tsz = 0;
    for(int i = l; i <= r; ++i) {
		if(abs(points[i].ff - midx) + eps < min_dist) { //eps
            for(int j = tsz-1; j >= 0 && points[i].ss - t[j].ss + eps < min_dist; --j) { //eps
				upd_ans(points[i], t[j]);
            }
            t[tsz++] = points[i];
		}
    }
}

void init(int n)
{
    sort(points, points+n);
    min_dist = inf;
    rec(0, n-1);
}
