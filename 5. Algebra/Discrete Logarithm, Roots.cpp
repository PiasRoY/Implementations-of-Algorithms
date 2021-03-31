/*
References:
1) https://math.stackexchange.com/questions/124408
2) https://math.stackexchange.com/questions/3262664
3) https://math.stackexchange.com/questions/166866
4) https://cp-algorithms.com/algebra/primitive-root.html
5) https://cp-algorithms.com/algebra/discrete-log.html
6) https://cp-algorithms.com/algebra/discrete-root.html
7) http://mathworld.wolfram.com/PrimitiveRoot.html
8) https://youtu.be/IviYLdqmIdw
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

    vector<ll> prime_factors;

    ll phi = p-1,  n = phi; //change phi for non-primes.
    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            prime_factors.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1) prime_factors.push_back (n);

    for (ll res = 2; res < p; res++) { //Complexity: O(p*sqrt(phi(p)))
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
//gives minimum 'x' such that (a^x)%m ; gcd(a, m) = 1;
ll discrete_log(ll a, ll b, ll m) //Complexity: O(sqrt(m)*log(m))
{
    unordered_map<ll, ll> vals;
    ll n = sqrt (m) + 1;

    for (ll q = 0, cur = b; q <= n; ++q) {
        vals[cur] = q;
        cur = (cur * a) % m;
    }

    ll an = bigmod(a, n, mod);

    for (ll p = 1, cur = 1; p <= n; ++p) {
        cur = (cur * an) % m;

        if (vals.count(cur)) {
            return n * p - vals[cur];
        }
    }

    return -1;
}

/*
Discrete Root (cp-algorithm)
x^k \equiv a (mod P), where P is prime. Find all possible 'x'.
Suppose, 'g' is a primitive root modulo P. So 'x' can be written as [g^y \equiv x (mod P)].
So, g^(y*k) \equiv a (mod P). Now find y using giant step-baby step algorithm. One possible answer is x = g^y.
after that to find all other x = g^{y+(i*(phi(n)/gcd(k, phi(n))))}

*/

//x^a = b (mod m), where m is prime
//(g^k)^a = b (mod m) => (g^a)^k = b (mod m), where g is primitive root
ll discrete_root(ll a, ll b, ll m)
{
    ll g = primitive_root(m);

    ll x = discrete_log(bigmod(g, a, mod), b, m);

    if(x != -1) {
        x = bigmod(g, x, m);
    }

    return x;

    // Print all possible answers
//    ll delta = (m-1) / __gcd(k, m-1);
//    vector<ll> ans;
//    for (ll cur = x % delta; cur < m-1; cur += delta)
//        ans.push_back(bigmod(g, cur, m));
//    sort(ans.begin(), ans.end());
//
//    printf("%d\n", ans.size());
//    for (ll answer : ans)
//        printf("%lld ", answer);
}

