typedef complex<double> Complex;
const double PI = acos(-1);

void fft(vector<Complex> &a, bool invert)
{
    int n = a.size(); // must be a power of 2.
    if (n == 1) return;

    vector<Complex> f(n / 2), g(n / 2);

    for(int i = 0; 2 * i < n; i++) {
        f[i] = a[2*i];
        g[i] = a[2*i + 1];
    }

    fft(f, invert);
    fft(g, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);

    Complex w(1), wn(cos(ang), sin(ang));

    for(int i = 0; 2 * i < n; i++) {
        Complex add = w * g[i]; // w = w_n ^ i

        a[i] = f[i] + add;
        a[i + n/2] = f[i] - add;

        w *= wn;
    }
}

void ifft(vector<Complex> &p)
{
    fft(p, 1);

    int sz = p.size();
    for(int i = 0; i < p.size(); ++i) p[i] /= sz;
}
