//implemented with the help of geeksforgeeks
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

//SegmentedTree; preprocess: O(NlogN), query: O(logN)
int tree[4*MX];

void build(int pos, int L, int R)
{
    if(L == R) {
        tree[pos] = L; //building according to index of discovery time
        return;
    }

    int mid = (L+R)/2;
    build(pos*2, L, mid);
    build(pos*2+1, mid+1, R);

    if(level[tree[pos*2]] < level[tree[pos*2+1]]) tree[pos] = tree[pos*2];
	else tree[pos] = tree[pos*2+1];
}

int query(int pos, int L, int R, int l, int r)
{
    if(l > R || r < L) return -1;
    if(L >= l && R <= r) return tree[pos];

    int mid = (L+R)/2;
    int Lidx = query(pos*2, L, mid, l, r);
    int Ridx = query(pos*2+1, mid+1, R, l, r);

    if(Lidx == -1) return Ridx;
    if(Ridx == -1) return Lidx;

    if(level[Lidx] < level[Ridx]) return Lidx;
    else return Ridx;
}

//LCA by RMQ; preprocess: O(NlogN), query: O(logN)
void lca_preprocess()
{
	dfs(1, 1);
	build(1, 1, dfs_counter-1);
}

int lca(int a, int b)
{
	int x, y;
	x = dis_time[a];
	y = dis_time[b];

	if(x < y) return euler[query(1, 1, dfs_counter-1, x, y)];
	else return euler[query(1, 1, dfs_counter-1, y, x)];
}
