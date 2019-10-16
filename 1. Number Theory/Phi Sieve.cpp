#define MX 3000005
llu tot[MX], res[MX];
void phi_sieve()
{
    for(int i = 1; i < MX; i++) {
        tot[i] = i;
        if(i%2==0) tot[i] -= tot[i]/2;
    }

    for(int i = 3; i < MX; i+=2) {
        if(tot[i] == i) {
            for(int j = i; j < MX; j+=i) {
                tot[j] -= tot[j]/i;
            }
        }
    }
}
