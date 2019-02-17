void bfs(int s) //Complexity: O(V+E)
{
	memset(vis, false, sizeof vis);
	memset(dist, inf, sizeof dist);
	queue <int> q;

	dist[s] = 0;
	q.push(s);


	while(!q.empty()) {
		int u = q.top();
		q.pop();

		for(int i = 0; i < adj[u].size(); i++) {
			int v = adj[x][i];

			if(!vis[v]) {
				vis[v] = true;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}
