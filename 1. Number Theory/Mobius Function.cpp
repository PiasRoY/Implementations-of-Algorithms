int mu[MX], primechk[MX];

void mobius()
{
	for(int i = 1; i < MX; i++) {
		mu[i] = primechk[i] = 1;
	}

	primechk[1] = 0;
	for(int i = 2; i < MX; i++) {
        if(primechk[i] == 1) {
            mu[i] = -mu[i];
            for(int j = 2; i*j < MX; j++) {
                primechk[i*j] = 0;
                if(j%i==0) mu[i*j] = 0;
                else mu[i*j] = -mu[i*j];
            }
        }
	}
}

//implement as multiplicative function
void linear_mobius()
{
	memset(is_composite, false, sizeof is_composite);

	mu[1] = 1;
	for(int i = 2; i < MX; i++) {
        if(!is_composite[i]) {
			mu[i] = -1;
			primes.pb(i);
        }

        for(int j = 0; j < primes.size() && i*primes[j] < MX; j++) {
            is_composite[i*primes[j]] = true;

            if(i%primes[j]==0) {
				mu[i*primes[j]] = 0;
				break;
            }
			else mu[i*primes[j]] = mu[i] * mu[primes[j]];
        }
	}
}
