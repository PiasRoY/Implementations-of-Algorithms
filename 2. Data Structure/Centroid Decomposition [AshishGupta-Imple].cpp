#define MX 100005
int nodes, subtree[MX], parentcentroid[MX];
set <int> adj[MX];

/*----------decompose part----------*/
void dfs(int u, int par) //O(V+E)
{
	nodes++;
	subtree[u]=1;
	for(auto it : adj[u]) {
		if(it == par) continue;
		dfs(it, u);
		subtree[u] += subtree[it];
	}
}

int centroid(int u, int par) //O(logN)
{
	for(auto v : adj[u]) {
		if(v == par) continue;
		if(subtree[v]>(nodes>>1)) {
			return centroid(v, u);
		}
	}
	return u;
}

void decompose(int u, int par) //O(NlogN)
{
	nodes = 0;
	dfs(u, u);

	int node = centroid(u, u);
	parentcentroid[node] = par;

	for(auto v : adj[node]) {
		adj[v].erase(node);
		decompose(v, node);
	}
}
/*-----------------------------------*/

//Problem 1: https://codeforces.com/contest/322/problem/E
//Solution 1: https://codeforces.com/contest/322/submission/45791742

//Problem 2: https://codeforces.com/contest/342/problem/E
//Solution 2: https://codeforces.com/contest/342/problem/E
