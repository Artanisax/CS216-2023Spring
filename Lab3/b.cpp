#include <iostream>
#include <algorithm>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef long long ll;

const int N = 1e6+5;

ll a[N], b[N];

int main()
{
    int n;
    ll avg = 0, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        avg += a[i];
    }
    avg /= n;
    for (int i = 1; i <= n; ++i)
        b[i] = b[i-1]+a[i]-avg;
    sort(b+1, b+n+1);
    for (int i = 1; i <= n; ++i)
        ans += abs(b[i]-b[n+1>>1]);
    cout << ans;
    return 0;
}