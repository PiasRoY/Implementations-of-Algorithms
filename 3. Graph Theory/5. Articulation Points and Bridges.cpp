void APB(int u)
{
	dfs_low[u] = dfs_no[u] = dfs_counter++;

	for(int j = 0; j < adj[u].size(); j++) {
		int v = adj[u][i];

		if(dfs_no[v] == -1) {
			dfs_parent[v] = u;

			if(u == dfsRoot) rootChildren++;

			APB(v);

			if(dfs_low[v] >= dfs_no[u]) //Articulation Points
				articulation_vertex[u] = true;

			if(dfs_low[v] > dfs_no[u]) //Articulation Bridges
				articulation_bridge.pb(mk(u, v));

			dfs_low[u] = min(dfs_low[u], dfs_low[v]); //update dfs_low[u]
		}
		else if(v != dfs_parent[u]) {
			dfs_low[u] = min(dfs_low[u], dfs_low[v]); //update dfs_low[u]
		}
	}
}

//Complexity: O(V+E)
void articulationPointandBridges(int n) //n = vertex number
{
	dfs_counter = 0;
	for(int i = 0; i < n; i++) { //0-based index
        articulation_vertex[i] = dfs_low[i] = dfs_parent[i] = 0;
        dfs_no[i] = -1;
	}

	for(int i = 0; i < n; i++) {
		if(dfs_no[i] == -1) {
			dfsRoot = i;
			rootChildren = 0;
			APB(i);
			articulation_vertex[dfsRoot] = (rootchildren > 1);
		}
	}

	//now check articulation_vertex & articulation_bridge for answer.
}
