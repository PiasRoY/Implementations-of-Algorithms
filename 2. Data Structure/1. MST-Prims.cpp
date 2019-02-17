//Prim's Algorithm
ll mst;
bool taken[MX];
vector <pll> edges[MX];

void prims_algo(ll start) //Complexity: O(ElogV), better for dense graph
{
    fill(taken, taken+MX, false);

    priority_queue <pll, vector<pll>, greater<pll> > pq;
    pq.push(mk(0, start));

    mst = 0;
    while(!pq.empty())
    {
        ll u = pq.top().ss, w = pq.top().ff;
        pq.pop();

        if(!taken[u]) {
			taken[u] = true;
			mst += w;

			for(ll i = 0; i < edges[u].size(); i++) {
				ll v = edges[u][i].ff, _w = edges[u][i].ss;

				if(!taken[v]) {
					pq.push(mk(_w, v));
				}
			}
        }
    }
}
