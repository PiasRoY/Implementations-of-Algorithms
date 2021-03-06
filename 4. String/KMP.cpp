int lps[MX];
char txt[MX], pat[MX];

void computeLPSArray(char *pat)
{
    int i = 1, len = 0, M = strlen(pat);

    lps[0] = 0;

    while(i < M) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len != 0) {
                len = lps[len - 1];
			}
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPSearch(char *txt, char *pat)
{
    int N = strlen(txt);
    int M = strlen(pat);

    int i = 0, j = 0;
    while(i < N) {
        if(pat[j] == txt[i]) {
            j++;
            i++;
        }

        if(j == M) {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }

        else if(i < N && pat[j] != txt[i]) {
            if(j != 0) j = lps[j - 1];
            else i++;
        }
    }
}
