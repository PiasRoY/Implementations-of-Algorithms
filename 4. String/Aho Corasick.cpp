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


//iterative + memorization
const int K = 26;
char str[502], txt[1000006];
int sz, num[MX], trie[MX][26], link[MX];


void add_string(char *s)
{
    int u = 0;
    for(int i = 0; s[i]; i++) {
        int c = s[i]-'a';
        if(trie[u][c] == -1)
            trie[u][c] = sz++;
        u = trie[u][c];
    }
    num[u] = 0;
}

void build_fail()
{
    queue <int> q;

    for(int i = 0; i < K; i++) {
        if(trie[0][i] != -1) {
            q.push(trie[0][i]);
            link[trie[0][i]] = 0;
        }
        else trie[0][i] = 0;
    }
    int p, u, v;
    while(!q.empty()) {
        p = q.front();
        q.pop();

        for(int c = 0; c < K; c++) {
            u = trie[p][c];
            if(u != -1) {
                q.push(u);
                v = link[p];
                while(trie[v][c]==-1)
                    v = link[v];
                link[u] = trie[v][c];
            }
        }
    }
}

int go(int v, char ch)
{
    int c = ch-'a';
    if(trie[v][c] != -1) return trie[v][c];

    int nxt = v;
    while(trie[nxt][c]==-1)
        nxt = link[nxt];
    nxt = trie[nxt][c];
    return trie[v][c] = nxt;
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

void init()
{
    sz = 1;
    memset(trie, -1, sizeof trie);
}
