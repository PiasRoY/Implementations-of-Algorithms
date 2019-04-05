//implementation is similar to CP3 section 9.18
//filling euler and level array using DFS in O(V+E)
#define MX 10

bool vis[MX];
int n, e, dfs_counter = 1;
int dis_time[MX], euler[MX*2], level[MX*2];

vector <int> adj[MX];

void dfs(int u, int lvl)
{
	dis_time[u] = dfs_counter;
	euler[dfs_counter] = u;
	level[dfs_counter++] = lvl;

	vis[u] = true;

	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];

		if(!vis[v]) {
			dfs(v, lvl+1);

			euler[dfs_counter] = u;
			level[dfs_counter++] = lvl;
		}
	}
}

//sparse table, Complexity- built: O(NlogN), query: O(1);
int spt[MX][MX];

void build(int n)
{
	for(int i = 1; i <= n; i++)
		spt[i][0] = i;

	for(int j = 1; (1 << j) <= n; j++) {
		for(int i = 1; (i + (1<<j) - 1) <= n; i++) {
			if(level[spt[i][j-1]] < level[spt[i + (1<<(j-1))][j-1]])
				spt[i][j] = spt[i][j-1];
			else
				spt[i][j] = spt[i+(1<<(j-1))][j-1];
		}
	}
}

int query(int L, int R)
{
	int j = log2(R - L + 1);

	if(level[spt[L][j]] < level[spt[R-(1<<j)+1][j]]) return spt[L][j];
	else return spt[R-(1<<j)+1][j];
}

//best to use sparse table for its static RMQ benefit
//LCA by RMQ; preprocess: O(NlogN), query: O(1)
void lca_preprocess()
{
	dfs(1, 1);
	build(dfs_counter-1);
}

int lca(int a, int b)
{
	int x, y;
	x = dis_time[a];
	y = dis_time[b];

	if(x < y) return euler[query(x, y)];
	else return euler[query(y, x)];
}
