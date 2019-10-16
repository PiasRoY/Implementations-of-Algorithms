int mx, node;
bool vis[MX];
vector <int> adj[MX];

void dfs(int u, int h)
{
	vis[u] = true;

    if(h > mx) mx = h, node = u;

    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
		if(!vis[v]) {
			dfs(v, h+1);
		}
    }
}

int main()
{
	mx = 0;
	memset(vis, 0, sizeof vis);
	dfs(1, 0);
	memset(vis, 0, sizeof vis);
	dfs(node, 0);
	DIAMETER = mx;
}
