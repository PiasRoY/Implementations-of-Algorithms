//x' = x + (k*B/g), y' = y - (k*A/g)
bool linearDiophantine ( int A, int B, int C, int *x, int *y) {
    int g = gcd(A, B);
    if (C%g != 0) return false; //No Solution
 
    int a = A/g, b = B/g, c = C/g;
    extended_gcd(a, b, x, y); //Solve ax + by = 1
 
    if (g < 0) { //Make Sure gcd(a,b) = 1
        a *= -1; b *= -1; c *= -1;
    }
 
    *x *= c; *y *= c; //ax + by = c
    return true; //Solution Exists
}