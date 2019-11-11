bool mark[MX];
vector <int> primes;

int segmentedSieve (int a, int b) {
    if(a == 1) a++;

    int sqrtN = sqrt(b), i, j, p;

    memset(mark, false, sizeof mark);

    for(i = 0; i < primes.size() && primes[i] <= sqrtN; i++) {
        p = primes[i];
        j = p * p;

        if(j < a) j = ( ( a + p - 1 ) / p ) * p;

        for ( ; j <= b; j += p) {
            mark[j-a] = true;
        }
    }

    int cnt = 0;
    for (i = a; i <= b; i++) {
        if (!mark[i-a]) cnt++;
        primes.pb(i);
    }
    return cnt;
}