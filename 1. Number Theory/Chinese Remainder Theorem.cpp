ll inv(ll a, ll m)
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;

    if (m == 1)
       return 0;

    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
       x1 += m0;

    return x1;
}

ll CRT(vector<ll>&num, vector<ll>&rem, ll k)
{
    ll prod = 1;
    for (ll i = 0; i < k; i++)
        prod *= num[i];

    ll result = 0;

    for (ll i = 0; i < k; i++)
    {
        ll pp = prod / num[i];
        result += rem[i] * inv(pp, num[i]) * pp;
    }

    return result % prod;
}

//CRT - Non coprime modulo | CF
#define MX 100005
ll a[MX], n[MX];

ll ex_gcd(ll a, ll b, ll &x, ll &y) {
	if(a == 0) {
		x = 0;
		y = 1;
		return b;
	}

	ll x1, y1, gcd;
	gcd = ex_gcd(b%a, a, x1, y1);
	x = y1 - (b/a) * x1;
	y = x1;

	return gcd;
}

ll norm(ll x, ll m) {
    x %= m;
    return (x<0) ? x+=m : x;
}

ll CRT()
{
    ll m, ans, lcm, x1, x2, g;

    scanf("%lld", &m);
    for(ll i = 1; i <= m; i++) {
        scanf("%lld %lld", &a[i], &n[i]);
        a[i] = norm(a[i], n[i]);
    }

    ans = a[1];
    lcm = n[1];
    for(ll i = 2; i <= m; i++)
    {
        g = ex_gcd(lcm, n[i], x1, x2);

        if((a[i] - ans) % g != 0) return 0; //no solution
        ans = norm(ans + x1 * (a[i] - ans) / g % (n[i] / g) * lcm, lcm * n[i] / g);
        lcm = lcm * n[i] / g;
    }

    return ans;
}


