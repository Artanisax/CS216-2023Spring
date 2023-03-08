#include <iostream>
#include <algorithm>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef pair<int, int> pii;

const int N = 505;

pii g[N];
bool t[N];

inline bool comp(const pii &a, const pii &b)
{ return a.second == b.second ? a.first < b.first : a.second > b.second; }

int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> g[i].first;
    for (int i = 1; i <= n; ++i)
        cin >> g[i].second;
    sort(g+1, g+n+1, comp);
    for (int i = 1; i <= n; ++i)
    {
        bool flag = false;
        for (int j = g[i].first; j; --j)
            if (!t[j])
            {
                t[j] = flag = true;
                break;
            }
        if (!flag)
            ans += g[i].second;
    }
    cout << ans;
    return 0;
}