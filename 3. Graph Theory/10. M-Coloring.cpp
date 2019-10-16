bool isSafe(int u, int c)
{
    for(auto v : adj[u]) {
        if(color[v] == c) return false;
    }
    return true;
}

bool M_Coloring(int v, int m)
{
    if(v == n+1) return true; //n = total vertices number

    for(int i = 1; i <= m; i++) { //m = max color can be used
        if(isSafe(v, i)) {
            color[v] = i;
            if(M_Coloring(v+1, m)) return true;
            color[v] = 0;
        }
    }

    return false;
}

/*
Moser Spindler Graph: 4-colorable
7 11
1 2
2 3
3 4
4 5
5 1
6 1
6 4
6 5
7 1
7 2
7 3
///5-colorable
5 10
1 2
2 3
3 1
4 1
4 2
4 3
5 1
5 2
5 3
5 4
*/

