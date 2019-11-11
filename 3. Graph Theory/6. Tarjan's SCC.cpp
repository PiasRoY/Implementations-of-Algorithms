/* SCC of undirected graph can also be found with this algo.
Just use an extra track of parent in tarjanSCC function, don't
do any operation whenever you go to the parent of a node. */

bool vis[MX];
vector <int> stck, adj[MX];
int numSCC, dfs_low[MX], dfs_no[MX], dfs_counter;

void tarjanSCC(int u)
{
	vis[u] = true;
	dfs_low[u] = dfs_no[u] = dfs_counter++;

	stck.pb(u);

	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];

		if(dfs_no[v] == -1) tarjanSCC(v);
		if(vis[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}

	if(dfs_low[u] == dfs_no[u]) {
		printf("SCC %d:", ++numSCC);
		while(true) {
			int v = stck.back();
			stck.pop_back();
			vis[v] = 0;
			printf(" %d", v);
			if(u == v) break;
		}
		printf("\n");
	}
}


//Complexity: O(V+E)
void tarjan(int n) //n = Vertex Number
{
	dfs_counter = numSCC = 0;
	for(int i = 0; i < n; i++) { //0-based index
        dfs_low[i] = vis[i] = 0;
        dfs_no[i] = -1;
	}

	for(int i = 0; i < n; i++) {
		if(dfs_no[i] == -1)
			tarjanSCC(i);
	}
}


int main()
{
	int n, m;
    scanf("%d %d", &n, &m);

    int u, v;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
    }

    tarjan(n);

}
