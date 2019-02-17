//Kruskal Algorithm
ll parent[MX], mst;
vector <pair<ll, pair<ll, ll> > > edgeslist; //(w, u, v)

ll fnd(ll x)
{
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void kruskal_algo() //Complexity: O(ElogV), better for sparse graph.
{
    //disjoint set
    for(int i = 0; i < MX; i++)
        parent[i] = i;

    sort(edgeslist.begin(), edgeslist.end());

    mst = 0;
    for(ll i = 0; i < edgeslist.size(); i++) {
        ll w = edgeslist[i].ff, u = edgeslist[i].ss.ff, v = edgeslist[i].ss.ss;
        ll pu = fnd(u), pv = fnd(v);

        if(pu != pv)
        {
            parent[pu] = pv;
            mst += edgeslist[i].ff;
        }
    }
}
