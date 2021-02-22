#define MX 1003

int n; //number of vertex
vector <int> adj[MX];
int par[MX], cap[MX][MX];

int bfs(int s, int t)
{
    int new_flow;
    queue <pii> q;
    memset(par, -1, 4 * n); //0-indexed

    par[s] = -2;
    q.push(mk(s, INT_MAX));

    while(!q.empty()) {
        pii u = q.front();
        q.pop();

        for(int v : adj[u.ff]) {
            if(par[v] == -1 && cap[u.ff][v] > 0)
            {
                par[v] = u.ff;
                new_flow = min(u.ss, cap[u.ff][v]);

                if(v == t)
                    return new_flow;

                q.push(mk(v, new_flow));
            }
        }
    }

    return 0;
}

int edmonds_karp(int s, int t) // O(V * E^2)
{
    int mxflow = 0, new_flow, cur;

    while(new_flow = bfs(s, t))
    {
        mxflow += new_flow;

        cur = t;
        while(cur != s) {
            cap[par[cur]][cur] -= new_flow;
            cap[cur][par[cur]] += new_flow;
            cur = par[cur];
        }
    }

    return mxflow;
}
