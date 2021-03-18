// Convex Hull
bool cmp(pt a, pt b)
{
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

void convex_hull(vector<pt> &pts)
{
    if(sz(pts) == 1)
        return;

    sort(pts.begin(), pts.end(), cmp);

    vector <pt> upHull, lowHull;

    int ort;
    pt A = pts[0];
    pt B = pts[sz(pts)-1];

    upHull.pb(A);
    lowHull.pb(A);

    for(int i = 1; i < sz(pts); ++i)
    {
        ort = orient(A, pts[i], B);

        if(i == sz(pts)-1 || ort < 0) {
            while(sz(upHull) >= 2 && orient(upHull[sz(upHull)-2], upHull[sz(upHull)-1], pts[i]) >= 0)
                upHull.pop_back();
            upHull.pb(pts[i]);
        }

        if(i == sz(pts)-1 || ort > 0) {
            while(sz(lowHull) >= 2 && orient(lowHull[sz(lowHull)-2], lowHull[sz(lowHull)-1], pts[i]) <= 0)
                lowHull.pop_back();
            lowHull.pb(pts[i]);
        }
    }

    pts.clear();
    for(pt e : upHull)
        pts.pb(e);
    for(int i = sz(lowHull)-2; i > 0; --i)
        pts.pb(lowHull[i]);
}
