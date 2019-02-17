//Bipartite graph has no odd cycle. Bipartite graph can have at most V^2/4 edges.

bool bipartite_check(int src) //Complexity : O(V+E)
{
	memset(color, -1, sizeof color);

	queue <int> q;

	q.push(src);
	color[src] = 0;

	bool isBipartite = true;

	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		for(int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];

			if(color[v] == -1) {
				color[v] = 1-color[u];
				q.push(v);
			}
			else if(color[u] == color[v]) {
				isBipartite = false;
				break;
			}
		}
	}

	return isBipartite;
}
