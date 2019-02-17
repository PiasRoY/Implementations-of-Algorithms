void bfs() //Complexity : O(V+E)
{
	queue <int> pq;
//	priority_queue <int, vector <int>, greater<int> > pq;

	for(int i = 0; i < k; i++)
		if(in_degree[i] == 0) // in_degree array contains node's indegree edges' count
			pq.push(i), level[i] = 0;

	while(!pq.empty()) {
		int u = pq.front(); //pq.top();
		pq.pop();

		topsort.pb(v);

		for(int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];

			if(--in_degree[v] == 0) {
				q.push(v);
			}
		}
	}
}
