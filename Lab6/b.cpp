#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef long long ll;
typedef pair<ll, ll> pll;

const int N = 1e5+5;

pll p[N], temp[N];

inline bool comp(const pll &a, const pll &b)
{ return a.second < b.second; }

inline ll dist(const pll &a, const pll &b)
{ return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second); }

ll merge(int l, int r)
{
    if (l == r)
        return LONG_LONG_MAX;
    if (r-l == 1)
        return dist(p[l], p[r]);
    int mid = l+r>>1, cnt = 0;
    ll ret = min(merge(l, mid), merge(mid+1, r));
    for (int i = l; i <= r; i++)
        if (abs(p[i].first-p[mid].first) < ret)
            temp[++cnt] = p[i];
    sort(temp+1, temp+cnt+1, comp);
    for (int i = 1; i < cnt; i++)
        for (int j = i+1; j <= cnt && temp[j].second-temp[i].second < ret; j++)
            ret = min(ret, dist(temp[i], temp[j]));
    return ret;
}

int main() 
{
    IO_accel();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].first >> p[i].second;
    sort(p+1, p+n+1);
    cout << merge(1, n);
    return 0;
}