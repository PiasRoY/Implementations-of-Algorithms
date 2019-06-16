#define MX 102

int chainNo=0;
int chainHead[MX], chainPos[MX], chainInd[MX], chainSize[MX];

void hld(int u) {

    if(chainHead[chainNo] == -1) {
        chainHead[chainNo] = u;
    }

    chainInd[u] = chainNo;
    chainPos[u] = chainSize[chainNo];
    chainSize[chainNo]++;

    int ind = -1, mai = -1, v;
    for(int i = 0; i < adj[u].size(); i++) {
        v = adj[u][i];

        if(subtree_size[v] > mai) {
            mai = subtree_size[v];
            ind = i;
        }
    }

    if(ind >= 0) hld(adj[u][ind]);

    for(int i = 0; i < adj[u].sz; i++) {
        if(i != ind) {
            chainNo++;
            hld(adj[u][i]);
        }
    }
}
