#define MX 1000006
vector <ll> primes;

void sieve() //O(NloglogN)
{
	for(int i = 3; i < MX; i += 2) {
		if(!mark[i]) {
			for(int j = i*i; j < MX; j += 2*i) {
				mark[j] = true;
			}
		}
	}

	primes.pb(2);
	for(int i = 3; i < MX; i+=2) {
		if(!mark[i])
			primes.pb(i);
	}
}

//Linear Complexity for Multiplicative Functions
bool is_composite[MX];
vector <ll> primes;

void linear_sieve() //O(N)
{
    memset(is_composite, false, sizeof is_composite);

    for(int i = 2; i < MX; i++) {
        if(!is_composite[i]) primes.pb(i);
        for(int j = 0; j < primes.size() && i*primes[j] < MX; j++) {
            is_composite[i*primes[j]] = true;
            if(i%primes[j]==0) break;
        }
    }
}
