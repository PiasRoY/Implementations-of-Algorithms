void dfs(int u) {
	vis[u] = 1;

	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];

		if(vis[v] == 0) dfs(v);
		else if(vis[v] == 1) return true;
	}

	vis[u] = 2;
	return false;
}