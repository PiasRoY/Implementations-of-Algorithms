int comp[MX];
bool vis[MX], asgnmnt[MX];
vector <int> adj[MX], tadj[MX], order;

void dfs1(int u)
{
    vis[u] = true;

    for(int v : adj[u]) {
        if(!vis[v]) {
            dfs1(v);
        }
    }
    order.push_back(u);
}

void dfs2(int u, int cl)
{
    comp[u] = cl;

    for(int v : tadj[u]) {
        if(comp[v] == -1) {
            dfs2(v, cl);
        }
    }
}

bool solve_2SAT(int n)
{
    order.clear();
    for(int i = 0; i < n; i++) {
        comp[i] = -1;
        vis[i] = asgnmnt[i] = false;
    }

    for(int i = 0; i < n; ++i) {
        if(!vis[i])
            dfs1(i);
    }

    for(int i = 0, j = 0; i < n; ++i) {
        int v = order[n-i-1];
        if(comp[v] == -1)
            dfs2(v, j++);
    }

    for(int i = 0; i < n; i += 2) {
        if(comp[i] == comp[i + 1])
            return false;
        asgnmnt[i/2] = comp[i] > comp[i + 1];
    }
    return true;
}
