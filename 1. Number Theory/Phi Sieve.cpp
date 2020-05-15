#define MX 3000005
ll phi[MX];
void phi_sieve()
{
    for(int i = 1; i < MX; i++) {
        phi[i] = i;
        if(i%2==0) phi[i] -= phi[i]/2;
    }

    for(int i = 3; i < MX; i+=2) {
        if(phi[i] == i) {
            for(int j = i; j < MX; j+=i) {
                phi[j] -= phi[j]/i;
            }
        }
    }
}

//Linear Complexity for Multiplicative Functions
ll phi[MX];
vector <ll> primes;
bool is_composite[MX];

void linear_phi_sieve()
{
	memset(is_composite, false, sizeof is_composite);

	phi[1] = 1;
    for(int i = 2; i < MX; i++) {
        if(!is_composite[i]) {
			phi[i] = i-1;
			primes.pb(i);
        }
        for(int j = 0; j < primes.size() && i*primes[j] < MX; j++) {
            is_composite[i*primes[j]] = true;

            if(i%primes[j]==0) {
				phi[i*primes[j]] = phi[i] * primes[j];
				break;
            }
            else {
                phi[i*primes[j]] = phi[i] * phi[primes[j]];
            }
        }
    }
}
