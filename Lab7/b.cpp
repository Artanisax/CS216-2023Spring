#include <iostream>
#include <cmath>
// #include <complex>
#include <cstring>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef long long ll;
// typedef complex<double> Complex_d;

class Complex_d
{
private:
    double r = 0, i = 0;

public:
    inline Complex_d() {}

    inline Complex_d(const double r, const double i) : r(r), i(i) {}

    inline double real()
    { return r; }

    inline double imaginary()
    { return i; }

    inline double real(double d)
    { return r = d; }

    inline Complex_d &operator=(const Complex_d &x)
    {
        r = x.r;
        i = x.i;
        return *this;
    }

    inline Complex_d &operator=(const double x)
    {
        r = x;
        i = 0;
        return *this;
    }

    inline Complex_d operator+(const Complex_d &x)
    { return Complex_d(r + x.r, i + x.i); }

    inline Complex_d operator-(const Complex_d &x)
    { return Complex_d(r - x.r, i - x.i); }

    inline Complex_d operator*(const Complex_d &x)
    { return Complex_d(r * x.r - i * x.i, r * x.i + i * x.r); }

    inline Complex_d &operator+=(const Complex_d &x)
    { return *this = (*this) + x; }

    inline Complex_d &operator-=(const Complex_d &x)
    { return *this = (*this) - x; }

    inline Complex_d &operator*=(const Complex_d &x)
    { return *this = (*this) * x; }

    friend Complex_d operator*(const double d, const Complex_d &cpd)
    { return Complex_d(d * cpd.r, d * cpd.i); }

    friend ostream &operator<<(ostream &os, const Complex_d &cpd)
    { return os << '(' << cpd.r << ", " << cpd.i << ')'; }
};

const Complex_d I(0, 1);
const int N = 2e6 + 5;
const double PI = M_PI, EPS = 1e-3;

char s[N];
int rev[N];
Complex_d t[N], r[N], a[N], b[N], c[N], tmp[N];

void fft(Complex_d* f, int n, int rev) {
    if (n == 1)
        return;
    for (int i = 0; i < n; i++)
        tmp[i] = f[i];
    for (int i = 0; i < n; i++)
        if (i&1)
            f[(n>>1)+(i>>1)] = tmp[i];
        else
            f[i>>1] = tmp[i];
    Complex_d *g = f, *h = f+(n>>1);
    fft(g, n>>1, rev);
    fft(h, n>>1, rev);
    Complex_d cur(1, 0), step(cos(2*PI/n), sin(2*PI*rev/n));
    for (int i = 0; i < (n>>1); i++)
        {
            tmp[i] = g[i]+cur*h[i];
            tmp[i+(n>>1)] = g[i]-cur*h[i];
            cur *= step;
        }
    for (int i = 0; i < n; i++)
        f[i] = tmp[i];
}

// inline void change(Complex_d *a, int n)
// {
//     for (int i = 0; i < n; ++i)
//     {
//         rev[i] = rev[i >> 1] >> 1;
//         if (i&1)
//             rev[i] |= n >> 1;
//     }
//     for (int i = 0; i < n; ++i)
//         if (i < rev[i])
//             swap(a[i], a[rev[i]]);
//     return;
// }

// inline void fft(Complex_d *a, int n, int flag)
// {
//     change(a, n);
//     for (int h = 2; h <= n; h <<= 1)
//     {
//         Complex_d wn(cos(2*PI/h), sin(flag*2*PI/h));
//         for (int j = 0; j < n; j += h)
//         {
//             Complex_d w(1, 0);
//             for (int k = j; k < j + h / 2; k++)
//             {
//                 Complex_d u = a[k];
//                 Complex_d t = w*a[k+h/2];
//                 a[k] = u+t;
//                 a[k+h/2] = u-t;
//                 w = w*wn;
//             }
//         }
//     }
//     if (flag == -1)
//         for (int i = 0; i < n; i++)
//             a[i].real(a[i].real()/n);
// }

int main()
{
    // double st = time(NULL);
    IO_accel();
    // freopen("x.in", "r", stdin);
    cin >> s;
    int len = strlen(s), n, p = 0;
    while ((1 << p) < len)
        p++;
    n = 1 << p + 1;

    for (int i = 0; i < len; i++)
    {
        t[i] = (s[i] == '?' ? 0 : s[i] - '0' + 1);
        r[len - 1 - i] = t[i];
    }

    for (int i = 0; i < len; i++)
    {
        a[i] = t[i] * t[i] * t[i];
        b[i] = r[i];
    }
    fft(a, n, 1);
    fft(b, n, 1);
    for (int i = 0; i < n; i++)
        c[i] = a[i] * b[i];

    for (int i = 0; i < len; i++)
    {
        a[i] = t[i] * t[i];
        b[i] = r[i] * r[i];
    }
    for (int i = len; i < n; i++)
        a[i] = b[i] = 0;
    fft(a, n, 1);
    fft(b, n, 1);
    for (int i = 0; i < n; i++)
        c[i] -= 2.0 * a[i] * b[i];

    for (int i = 0; i < len; i++)
    {
        a[i] = t[i];
        b[i] = r[i] * r[i] * r[i];
    }
    for (int i = len; i < n; i++)
        a[i] = b[i] = 0;
    fft(a, n, 1);
    fft(b, n, 1);
    for (int i = 0; i < n; i++)
        c[i] += a[i] * b[i];

    fft(c, n, -1);

    ll ans = 0;
    for (int i = 0; i < len>>1; i++)
        ans ^= (abs(c[i].real()) < EPS) ? (ll)(i + 1) * (i + 1) : 0;
    cout << ans;
    // cerr << "\ntime cost: " << time(NULL) - st;
    return 0;
}