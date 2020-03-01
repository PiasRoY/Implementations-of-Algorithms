#define MX 100005
int n, arr[MX], dp[MX];

int dfs(int pos) {
	if(dp[pos] != -1) return dp[pos];

	dp[pos] = 0;
	for(int i = pos+1; i < n; i++) {
		if(arr[i] >= arr[pos]) {
			dp[pos] = max(dp[pos], dfs(i));
		}
	}

	return dp[pos] += 1;
}

int lcs() {
	for(int i = 0; i < n; i++) dp[i] = -1;

	int longest = 0;
	for(int i = 0; i < n; i++) {
		longest = max(longest, dfs(i));
	}

	return longest;
}
