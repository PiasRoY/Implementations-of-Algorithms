bool AP[MX];
vector <int> adj[MX];
int root, dfs_counter, rootch;
int low[MX], dfsno[MX], par[MX];

void APB(int u)
{
	low[u] = dfsno[u] = dfs_counter++;

	for(int v : adj[u]) {
		if(dfsno[v] == -1) {
			par[v] = u;
			if(u == root) rootch++;

			APB(v);

			if(low[v] >= dfsno[u]) AP[u] = true;
			low[u] = min(low[u], low[v]);
		}
		else if(v != par[u])
			low[u] = min(low[u], dfsno[v]);
	}
}

void articulationPoints(int n)
{
	dfs_counter = 0;
	for(int i = 1; i <= n; i++) {
        dfsno[i] = -1;
        AP[i] = low[i] = par[i] = 0;
	}

	for(int i = 1; i <= n; i++) {
		if(dfsno[i] == -1) {
			root = i, rootch = 0;
			APB(i);
			AP[root] = (rootch > 1);
		}
	}

	//work on APB from here
}
