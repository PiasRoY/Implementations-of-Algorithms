//Heavy Light Decomposition
#define MX 100005

int cur_pos;
vector <int> adj[MX];
int parent[MX], depth[MX], heavy[MX], head[MX], pos[MX];

int dfs(int u) { //Complexity: O(V+E)
    int sz = 1, mx = 0;

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];

        if (v != parent[u]) {
            parent[v] = u, depth[v] = depth[u] + 1;

            int subtree_sz = dfs(v);
            sz += subtree_sz;
            if (subtree_sz > mx) {
                mx = subtree_sz, heavy[u] = v;
            }
        }
    }

    return sz;
}

void decompose(int u, int h) { //Complexity: O(V+E)
    head[u] = h, pos[u] = cur_pos++;

    if (heavy[u] != -1) {
        decompose(heavy[u], h);
    }

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];

        if (v != parent[u] && v != heavy[u])
            decompose(v, v);
    }
}

void gen(int n) { //Complexity: O(V+E)
    for(int i = 0; i < n; i++) heavy[i] = -1;
    cur_pos = 0;

    dfs(0);
    decompose(0, 0);
}

//query to find the maximum value between two nodes in tree
int query(int a, int b) { //Complexity: O(logN)
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]]) {
            swap(a, b);
        }
        int cur_heavy_path_max = segment_tree_query(pos[head[b]], pos[b]);
        res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b]) {
        swap(a, b);
    }
    int last_heavy_path_max = segment_tree_query(pos[a], pos[b]);
    res = max(res, last_heavy_path_max);
    return res;
}
