void tarjanSCC(int u)
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;

	S.pb(u);
	visit[u] = true;

	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];

		if(dfs_num[v] == UNVISITED)
			tarjanSCC(v);
		if(visit[v])
			dfs_low[u] = min(dfs_num[u], dfs_low[v]);

		if(dfs_low[u] == dfs_num[u]) {
			printf("SCC %d:", ++numSCC); //total number of SCC
			while(true) {
				int v = S.back();
				S.pop_back();
				// visit[v] = 0; // if necessary
				printf("%d", v);
				if(u == v) break;
			}
			printf("\n");
		}
	}
}

void tarjan() //Complexity: O(V+E)
{
	dfsNumberCounter = numSCC = 0;
	memset(visit, false, sizeof visit);
	memset(dfs_low, 0, sizeof dfs_low);
	memset(dfs_num, UNVISITED, sizeof dfs_num);

	for(int i = 0; i < V; i++) {//V = Vertex Number
		if(dfs_num[i] == UNVISITED)
			tarjanSCC(i);
	}
}
