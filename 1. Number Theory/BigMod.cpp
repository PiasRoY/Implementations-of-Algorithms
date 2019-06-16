
//Bigmod - Repeated Squaring Method.

int bigmod (int b, int p, int m) {
    int res = 1, x = b % m;
    while (p > 0) {
        if (p & 1) res = (res * x) % m;
        x = (x * x) % m;
        p >>= 1;
    }
    return res;
}
