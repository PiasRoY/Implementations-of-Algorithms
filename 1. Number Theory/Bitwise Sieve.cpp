#define MX 100000000
vector <llu> primes;
int status[(MX/32)+2];

bool Check(llu N,llu pos)
{
    return (bool)(N & (1<<pos));
}

int Set(llu N,llu pos)
{
    return N = N | (1<<pos);
}

void bit_sieve(llu N) //Complexity: O(NloglogN)
{
    llu sqrtN,i,j;
    sqrtN =  (sqrt(N));

    for(i = 3; i <= sqrtN; i += 2) {
        if(Check(status[i>>5],i&31) == 0) {
            for(j = i*i; j <= N; j += (i<<1)) {
                status[j>>5] = Set(status[j>>5], j&31);
            }
        }
    }

    primes.push_back(2);
    for(i = 3; i <= N; i += 2) {
        if( Check(status[i>>5],i&31)==0) {
            primes.push_back(i);
        }
    }
}
