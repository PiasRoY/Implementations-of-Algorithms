//implementation by pointer

const int ALPHABET_SIZE = 26;

typedef struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];
	bool isEndOfWord;
} TrieNode;

struct TrieNode *getNode(void)
{
	TrieNode *pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

void insert(TrieNode *root, string &key)
{
	TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	pCrawl->isEndOfWord = true;
}

bool search(TrieNode *root, string &key)
{
	TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl != NULL && pCrawl->isEndOfWord);
}

void del(TrieNode *cur) // for destruction of whole trie
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (cur->children[i])
            del(cur->children[i]);

    delete (cur);
}

//implementation by 2D array

#define MX_LEN 100
#define MX_NODE 100000
#define alphabet_size 26

char S[MX_LEN];

int root, nnode;
int isWord[MX_NODE];
int node[MX_NODE][alphabet_size];

void initailize()
{
	root = 0;
	nnode = 0;
	for(int i = 0; i < alphabet_size; i++)
		node[root][i] = -1;
}

void insert()
{
	scanf("%s", S);

	int now, len, index;

	len = strlen(S);
	now = root;

	for(int i = 0; i < len; i++) {
		index = s[i]-'a';

		if(node[now][index] == -1) {
			node[now][index] = ++nnode;
			for(int j = 0; j < alphabet_size; j++)
				node[nnode][j] = -1;
		}
		now = node[now][index];
	}

	isWord[now] = 1;
}
