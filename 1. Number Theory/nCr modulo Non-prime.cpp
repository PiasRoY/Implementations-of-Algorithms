struct nCr_M {

    ll fact[5][MX]; //MX = max(P_i^A_i)
    vector <pll> pdivs;

    nCr_M(ll M)
    {
        pfacts(M);
        gen();
    }

    void pfacts(ll m) {
        for(ll i = 2, cnt; i*i < m; ++i) {
            if(m%i==0) {
                cnt = 0;
                while(m%i==0) {
                    ++cnt;
                    m /= i;
                }
                pdivs.pb(mk(i, cnt));
            }
        }
        if(m!=1) pdivs.pb(mk(m, 1));
    }

    void gen() {
        for(ll i = 0, mod; i < sz(pdivs); ++i) {

            fact[i][0] = 1;
            mod = power(pdivs[i].ff, pdivs[i].ss);

            for(ll j = 1; j < mod; ++j) {
                fact[i][j] = fact[i][j-1];
                if(j%pdivs[i].ff)
                    fact[i][j] = (fact[i][j] * j) % mod;
            }
        }
    }

    ll ppow(ll n, ll p) {
        ll pcnt = 0, pp = p;
        while(pp <= n) {
            pcnt += n/pp;
            pp *= p;
        }
        return pcnt;
    }

    ll spf(ll x, ll p, ll pindx, ll mod) {
        ll ret = bigmod(fact[pindx][mod-1], x/mod, mod);
        if(x >= p) ret = ret * spf(x/p, p, pindx, mod) % mod;
        return ret = ret * fact[pindx][x%mod] % mod;
    }

    // mod inverse
    void ex_gcd(ll a, ll b, ll & x, ll & y) {
        if (a == 0) {
            x = 0, y = 1;
            return;
        }
        ll x1, y1;
        ex_gcd(b % a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
    }

    ll modInv(ll a, ll m) {
        ll x, y;
        ex_gcd(a, m, x, y);
        return (x % m + m) % m;
    }

    // CRT
    ll norm(ll x, ll m) {
        x %= m;
        return (x<0) ? x+=m : x;
    }

    ll CRT(vector<ll> &mods, vector<ll> &rems) {
        ll sz=sz(mods), ans=rems[0], lcm=mods[0], x1, x2;
        for(ll i = 1; i < sz; i++) {
            ex_gcd(lcm, mods[i], x1, x2);
            ans = norm(ans+x1*(rems[i]-ans)%(mods[i])*lcm, lcm*mods[i]);
            lcm = lcm * mods[i];
        }
        return ans;
    }

    // solution
    ll nCr(ll n, ll r)
    {
        ll z, rem, mod;
        vector <ll> mods, rems;

        for(ll i = 0; i < sz(pdivs); ++i) {

            z = ppow(n, pdivs[i].ff) - ppow(r, pdivs[i].ff) - ppow(n-r, pdivs[i].ff);

            mod = power(pdivs[i].ff, pdivs[i].ss);

            if(z >= pdivs[i].ss) rem = 0;
            else {
                rem = power(pdivs[i].ff, z);
                rem = rem * spf(n, pdivs[i].ff, i, mod) % mod;
                rem = rem * modInv(spf(r, pdivs[i].ff, i, mod), mod) % mod;
                rem = rem * modInv(spf(n-r, pdivs[i].ff, i, mod), mod) % mod;
            }

            rems.pb(rem);
            mods.pb(mod);
        }

        return CRT(mods, rems);
    }
};
