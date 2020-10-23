/*__________recursive approach__________*/

//source: CP-algo
const int K = 26;

struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        memset(go, -1, sizeof go);
        memset(next, -1, sizeof next);
    }
};

vector<Vertex> t(1);

void add_string(char *s) {
    int v = 0;
    for (int i = 0; s[i]; i++) {
        int c = s[i] - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, s[i]);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}

int get_exit_link(int v)
{
    if(v == 0) return 0;
    if(t[v].exit_link != -1) return t[v].exit_link;

    t[v].exit_link = t[v].leaf + get_exit_link(get_link(v));

    return t[v].exit_link;
}

void get_exit_link(int v)
//don't use this recursive approach
//rather store all exit vertices in each node
//through iterative approach
//use my another sol: https://codeforces.com/contest/963/submission/80216673
{
    if(t[v].leaf) num[a]++;

    if(t[v].exit_link != -1) {
        if(t[v].exit_link != 0) {
            get_exit_link(t[v].exit_link);
        }
        return;
    }

    int link = get_link(v);
    if(link == 0) {
        t[v].exit_link = 0;
        return;
    }

    get_exit_link(link);
    if(t[link].leaf) t[v].exit_link = link;
    else t[v].exit_link = t[link].exit_link;
}
/* _________________________________________ */



/* __________iterative approach__________ */
const int K = 26;

struct node {
    int nxt[K];
    node () {
        memset(nxt, -1, sizeof nxt);
    }
};

vector <node> trie(1);

int link[MX];
char str[10004], txt[1000006];

void add_string(char *s)
{
    int u = 0, c;
    for(int i = 0; s[i]; i++) {
        c = convrt_char(s[i]);

        if(trie[u].nxt[c] == -1) {
            trie[u].nxt[c] = trie.size();
            trie.pb(node());
        }
        u = trie[u].nxt[c];
    }
}

void suffix_link()
{
    int p, u, v;
    queue <int> q;

    for(int i = 0; i < K; i++) {
        if(trie[0].nxt[i] != -1) {
            q.push(trie[0].nxt[i]);
            link[trie[0].nxt[i]] = 0;
        }
        else trie[0].nxt[i] = 0;
    }

    while(!q.empty()) {
        p = q.front();
        q.pop();

        for(int c = 0; c < K; c++) {
            u = trie[p].nxt[c];
            if(u != -1) {
                q.push(u);

                v = link[p];
                while(trie[v].nxt[c]==-1)
                    v = link[v];
                link[u] = trie[v].nxt[c];
                /*//to store occurrences at each vertex
                for(int exL : occ[link[u]]) {
                    occ[u].pb(exL);
                }*/
            }
        }
    }
}

int go(int v, char ch)
{
    int c = convrt_char(ch);

    if(trie[v].nxt[c] != -1) return trie[v].nxt[c];

    int p = v;
    while(trie[p].nxt[c]==-1)
        p = link[p];
    p = trie[p].nxt[c];

    return trie[v].nxt[c] = p;
}

void exit_link(int v)
{
    while(v) {
        num[v]++;
        v = link[v];
    }
}

void match(char *s)
{
    for(int i = 0, v = 0; s[i]; i++) {
        v = go(v, s[i]);
        exit_link(v);
    }
}

/*------------------------------------------------*/
