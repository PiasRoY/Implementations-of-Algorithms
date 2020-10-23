///Persistent TRIE
const int K = 2;
const int MX = 33*300005; //take extra node for each root

int nnode, node[MX][K], root[300005], val[300005];

void init()
{
	nnode = 0;
	root[0] = 0;
	for(int i = 0; i < K; ++i) node[0][i] = -1;
}

void update(int pnow, int i)
{
	root[i] = ++nnode;
	int now = nnode, n = val[i], indx;

	for(int i = 30; i >= 0; --i) {
        if(n & (1<<i)) indx = 1;
        else indx = 0;

        for(int j = 0; j < K; ++j) {
			if(indx == j) {
				node[now][indx] = ++nnode;
				for(int l = 0; l < K; ++l)
					node[nnode][l] = -1;
			}
			else if(pnow != -1) node[now][j] = node[pnow][j];
			else node[now][j] = -1;
        }

		now = node[now][indx];
		if(pnow != -1) pnow = node[pnow][indx];
	}
}
