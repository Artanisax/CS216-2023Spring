#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef complex<double> complexd;

const complexd I(0, 1);
const int N = 4e5+5;
const double PI = M_PI;

complexd a[N], b[N], c[N], tmp[N];

void fft(complexd* f, int n, int rev) {
    if (n == 1)
        return;
    for (int i = 0; i < n; i++)
        tmp[i] = f[i];
    for (int i = 0; i < n; i++)
        if (i&1)
            f[(n>>1)+(i>>1)] = tmp[i];
        else
            f[i>>1] = tmp[i];
    complexd *g = f, *h = f+(n>>1);
    fft(g, n>>1, rev);
    fft(h, n>>1, rev);
    complexd cur(1, 0), step(cos(2*PI/n), sin(2*PI*rev/n));
    for (int i = 0; i < (n>>1); i++)
        {
            tmp[i] = g[i]+cur*h[i];
            tmp[i+(n>>1)] = g[i]-cur*h[i];
            cur *= step;
        }
    for (int i = 0; i < n; i++)
        f[i] = tmp[i];
}

int main()
{
    IO_accel();
    int n, m;
    cin >> n;
    m = n;
    if ((int)log2(n) != log2(n))
        n = (int)pow(2, floor(log2(n))+1);
    n <<= 1;
    for (int i = 0; i < m; i++)
    {
        double q;
        cin >> q;
        a[i] = q;
        c[m-i-1] = a[i];
        b[i] = i ? 1.0/i/i : 0;
    }
    fft(a, n, 1);
    fft(b, n, 1);
    fft(c, n, 1);
    for (int i = 0; i < n; i++)
    {
        a[i] *= b[i];
        c[i] *= b[i];
    }
    fft(a, n, -1);
    fft(c, n, -1);
    for (int i = 0; i < m; i++)
        cout << fixed << setprecision(3) << a[i].real()/n-c[m-i-1].real()/n << '\n';
    return 0;
}