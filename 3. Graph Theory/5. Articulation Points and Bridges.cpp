void APB(int u)
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;

	for(int j = 0; j < adj[u].size(); j++) {
		int v = adj[u][i];

		if(dfs_num[v] == UNVISITED) {
			dfs_parent[v] = u;

			if(u == dfsRoot) rootChildren++;

			APB(v);

			if(dfs_low[v] >= dfs_num[u]) //Articulation Points
				articulation_vertex[u] = true;

			if(dfs_low[v] > dfs_num[u]) //Articulation Bridges
				articulation_bridge.pb(mk(u, v));

			dfs_low[u] = min(dfs_low[u], dfs_low[v]); //update dfs_low[u]
		}
		else if(v != dfs_parent[u]) {
			dfs_low[u] = min(dfs_low[u], dfs_low[v]); //update dfs_low[u]
		}
	}
}

void articulationPointandBridges() //Complexity: O(V+E)
{
	dfsNumberCounter = 0;
	memset(dfs_low, 0, sizeof dfs_low);
	memset(dfs_parent, 0, sizeof dfs_parent);
	memset(dfs_num, UNVISITED, sizeof dfs_num);
	memset(articulation_vertex, false, sizeof articulation_vertex);

	for(int i = 0; i < V; i++) { //V = Vertex Number
		if(dfs_num[i] == UNVISITED) {
			dfsRoot = i;
			rootChildren = 0;
			APB(i);
			articulation_vertex[dfsRoot] = (rootchildren > 1);
		}
	}

	//now check articulation_vertex & articulation_bridge for answer.
}
