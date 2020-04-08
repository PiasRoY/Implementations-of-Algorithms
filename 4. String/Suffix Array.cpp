#define MX 100005

int n;
char str[MX];
int cnt[MX];
int RA[MX], tempRA[MX];
int SA[MX], tempSA[MX];

void countingSort(int k) //O(N)
{
	int i, sm, mx = max(300, n);

	memset(cnt, 0, sizeof cnt);

	for (i = 0; i < n; i++) {
		if(i+k < n) cnt[RA[i+k]]++;
		else cnt[0]++;
	}
	for (i = 1; i < mx; i++) cnt[i] += cnt[i-1];

	for (i = n-1; i >= 0; i--) {
		if(SA[i]+k < n) tempSA[--cnt[RA[SA[i]+k]]] = SA[i];
		else tempSA[--cnt[0]] = SA[i];
	}
	for (i = 0; i < n; i++) SA[i] = tempSA[i];
}

void constructSA() //O(NlogN)
{
	int i, k, r;

	for (i = 0; i < n; i++) RA[i] = str[i];
	for (i = 0; i < n; i++) SA[i] = i;

	for (k = 1; k < n; k <<= 1) {
		countingSort(k);
		countingSort(0);

		tempRA[SA[0]] = r = 0;
		for (i = 1; i < n; i++) {
			if(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) {
				tempRA[SA[i]] = r;
			}
			else tempRA[SA[i]] = ++r;
		}
		for (i = 0; i < n; i++) {
			RA[i] = tempRA[i];
		}
		if (RA[SA[n-1]] == n-1) break;
	}
}

int Phi[MX], PLCP[MX], LCP[MX];

void computeLCP() //O(N)
{
	Phi[SA[0]] = -1;

	int i, L;

	for(i = 1; i < n; i++) Phi[SA[i]] = SA[i-1];
	for(i = L = 0; i < n; i++) {
		if(Phi[i] == -1) {
			PLCP[i] = 0;
			continue;
		}
		while(str[i + L] == str[Phi[i] + L]) L++;
		PLCP[i] = L;
		L = max(L-1, 0);
	}
	for(i = 0; i < n; i++) LCP[i] = PLCP[SA[i]];
}
