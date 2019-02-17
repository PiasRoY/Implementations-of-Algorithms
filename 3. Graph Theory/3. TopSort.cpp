void dfs(int u) //Complexity: O(V+E)
{
	vis[u] = true;

	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];

		if(!vis[v]) {
			dfs(v);
		}
	}

	topsort.push_back(u);
}
