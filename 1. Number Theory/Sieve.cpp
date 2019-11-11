#define MX 1000006
vector <ll> primes;

void sieve() {
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