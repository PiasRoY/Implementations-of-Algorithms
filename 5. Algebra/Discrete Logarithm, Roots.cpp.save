/*
References:
1) https://math.stackexchange.com/questions/124408
2) https://math.stackexchange.com/questions/3262664
3) https://cp-algorithms.com/algebra/primitive-root.html
4) https://cp-algorithms.com/algebra/discrete-log.html
5) https://cp-algorithms.com/algebra/discrete-root.html
6) http://mathworld.wolfram.com/PrimitiveRoot.html
7) https://youtu.be/IviYLdqmIdw
*/

ll bigmod (ll b, ll p, ll m) {
    ll res = 1, x = b % m;
    while (p > 0) {
        if (p & 1) res = (res * x) % m;
        x = (x * x) % m;
        p >>= 1;
    }
    return res;
}

/*primitive root
[The following code assumes that the modulo p is a prime number.
 To make it works for any value of p, we must add calculation of phi(p).]

**function primitive_root will return lowest primitive root of p.
**if a is lowest primitive root then all other primitive roots are (a^m) % mod, when gcd(m, phi(mod)) = 1.
**the number of primitive roots modulo n, if there are any, is equal to phi(phi(n))
*/

ll primitive_root(ll p) //Complexity: O((logP)^6)
{

    vector<int> prime_factors;

    ll phi = p-1,  n = phi;
    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            prime_factors.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1) prime_factors.push_back (n);

    for (ll res = 2; res <= p; res++) { //Complexity: O(p*sqrt(phi(p)))
        bool ok = true;

        for (ll i = 0; i < prime_factors.size() && ok; i++) {
            ll x = bigmod(res, phi / prime_factors[i], p);

            if(x == 1) ok = false;
        }

        if (ok)  return res;
    }
    return -1;
}

/*
Instead of a map, we can also use a hash table (unordered_map in C++)
which has the average time complexity O(1) for inserting and searching.
*/

ll discrete_log(ll a, ll b, ll m) //Complexity: O(sqrt(m)*log(m))
{
    ll n = sqrt (m) + 1;

    ll an = 1;
    for (ll i = 0; i < n; ++i)
        an = (an * a) % m;

    map<int, int> vals;
    for (ll p = 1, cur = an; p <= n; ++p) {
        if (!vals.count(cur)) vals[cur] = p;
        cur = (cur * an) % m;
    }

    for (ll q = 0, cur = b; q <= n; ++q) {
        if (vals.count(cur)) {
            ll ans = vals[cur] * n - q;
            return ans;
        }
        cur = (cur * a) % m;
    }
    return -1;
}

/*
Discrete Root (cp-algorithm)
*/



