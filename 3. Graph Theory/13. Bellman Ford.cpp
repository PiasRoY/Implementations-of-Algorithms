bool bellman_ford(int n)
{
	fill(dist, dist+MX, inf);

	dist[1] = 0;
	for(int i = 1; i < n; i++) {
        for(auto e : edges) {
			if(dist[e.ff.ss] != inf) {
				dist[e.ff.ss] = min(dist[e.ff.ss], dist[e.ff.ff] + e.ss);
			}
        }
	}

    for(auto e : edges) {
        if(dist[e.ff.ff] != inf && dist[e.ff.ss] > dist[e.ff.ff] + e.ss) {
            return false;
        }
    }
    return true;
}
