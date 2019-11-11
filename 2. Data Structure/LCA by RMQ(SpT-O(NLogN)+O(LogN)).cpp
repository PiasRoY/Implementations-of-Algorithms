//LCA using sparse table; Complexity: O(NlgN,lgN)
int depth[MX], par[MX], lca[MX][18];

void dfs(int from, int u, int h)
{
    par[u] = from;
    depth[u] = h;

    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(v != from) {
			dfs(u, v, h+1);
        }
    }
}

void lca_init(int N) //Complexity: O(NlogN)
{
	dfs(0, 0, 0);

	memset(lca, -1, sizeof lca);

	int i, j;
	for (i = 1; i <= N; i++)
		lca[i][0] = par[i];

	for (j = 1; (1 << j) <= N; j++)
		for (i = 0; i <= N; i++)
			if(lca[i][j-1] != -1)
				lca[i][j] = lca[lca[i][j - 1]][j - 1];
}

int lca_query(int p, int q) //Complexity: O(logN)
{
	int i, pow2;

	if (depth[p] < depth[q]) swap(p, q);

	pow2 = 1;
	while(true) {
		int next = pow2+1;

        if((1<<next) > depth[p])break;
        else pow2++;
	}

	for (i = pow2; i >= 0; i--)
		if ((depth[p] - (1 << i)) >= depth[q])
			p = lca[p][i];

	if (p == q)
		return p;

	for (i = pow2; i >= 0; i--)
		if (lca[p][i] != -1 && lca[p][i] != lca[q][i])
			p = lca[p][i], q = lca[q][i];

	return par[p];
}
