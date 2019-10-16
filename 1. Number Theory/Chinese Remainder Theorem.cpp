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

ll CRT(vector<ll>num, vector<ll>rem, ll k)
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
