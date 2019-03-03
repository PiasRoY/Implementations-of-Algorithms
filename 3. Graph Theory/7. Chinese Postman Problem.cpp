int perfect_matching(int mask, int prev)
{
	if(mask == (1<<odd_vertices.size())-1) return 0;

	int &ret = dp[mask][prev];
	if(ret != -1) return ret;

	int ans;
	ret = inf;

	for(int i = 0; i < odd_vertices.size(); i++) {
		if((mask & (1<<i)) == 0) {
			ans = perfect_matching(mask | (1<<i), odd_vertices[i]);

			if(__builtin_popcount(mask) % 2)
				ans += mat[prev][odd_vertices[i]];

			ret = min(ret, ans);
		}
	}

	return ret;
}

void chinese_postman_problem(int sum) //Complexity: floyd_warshall[O(n^3)] + perfect_matching[O(mask*prev)]
{
	odd_vertices.clear();

	find_odd(); //storing all odd nodes in odd_vertices vector
	floyd_warshall(); //run a floyd warshall on the graph

	memset(dp, -1, sizeof dp);

	ans = sum + perfect_matching(0, 0); //sum contains 'sum of the all the edges of the graph'.
}
