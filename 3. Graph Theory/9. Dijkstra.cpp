void djk(int srcx)
{
	fill(dist, dist+MX, inf);
	fill(vis, vis+MX, false);

	priority_queue <pii, vector <pii>, greater <pii> > pq;

	pq.push(mk(0, srcx));
	dist[srcx] = 0;

	while(!pq.empty()) {
		auto u = pq.top();
		pq.pop();

		if(vis[u.ss]) continue;

		vis[u.ss] = true;
		for(int i = 0; i < adj[u.ss].size(); i++) {
			auto v = adj[u.ss][i];

			if(dist[v.ff] > dist[u.ss] + v.ss) {
				dist[v.ff] = dist[u.ss] + v.ss;
				pq.push(mk(dist[v.ff], v.ff));
			}
		}
	}
}
