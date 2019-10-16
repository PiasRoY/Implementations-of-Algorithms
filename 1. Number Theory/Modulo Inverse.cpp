//little Fermat's law, when modulo is prime: bigmod(a, p-2, p);

//Using extended euclidean algorithm, when gcd(a, m) = 1;

int extended_euclidean(int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extended_euclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

//how to use extended_euclidean algo to find mod inverse.
int modInv(int a, int m) {
	int x, y, g;

	g = extended_euclidean(a, m, x, y);

	if (g != 1) return -1; //no solution
	else {
		int mod_inv = (x % m + m) % m;
		return mod_inv;
	}
}

