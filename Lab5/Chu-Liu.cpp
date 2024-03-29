#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef pair<int, int> pii;

const int N = 1e3+5, M = 1e4+5, SUM = 1e6;

int n, m, r, cnt, fa[N], tp[N], id[N], mn[N];
struct Edge {
    int u, v, w;
} e[M];

int Chu_Liu()
{
    int ans = 0;
    while (true)
    {
        for (int i = 1; i <= n; ++i)
        {
            fa[i] = tp[i] = id[i] = 0;
            mn[i] = INT_MAX;
        }
        for (int i = 1, u, v, w; i <= m; ++i)
        {
            u = e[i].u, v = e[i].v, w = e[i].w;
            if (u != v && w < mn[v])
            {
                mn[v] = w;
                fa[v] = u;
            }
        }
        mn[r] = 0;
        cnt = 0;
        for (int u = 1, v; u <= n; ++u)
        {
            if (mn[u] == INT_MAX)
                return -1;
            ans += mn[u];
            for (v = u; tp[v] != u && v != r && !id[v]; v = fa[v])
                tp[v] = u;
            if (v != r && !id[v])
            {
                id[v] = ++cnt;
                for (int t = fa[v]; t != v; t = fa[t])
                    id[t] = cnt;
            }
        }
        if (!cnt)
            break;
        for (int i = 1; i <= n; ++i)
            if (!id[i])
                id[i] = ++cnt;
        for (int i = 1; i <= m; ++i)
        {
            e[i].w -= mn[e[i].v];
            e[i].u = id[e[i].u];
            e[i].v = id[e[i].v];
        }
        n = cnt;
        r = id[r];
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    r = n+1;
    int u, v, w;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v >> w;
        ++u, ++v;
        if (u != v)
            e[++cnt] = (Edge){u, v, w};
    }
    for (int i = 1; i <= n; ++i)
        e[++cnt] = (Edge){r, i, SUM};
    ++n, m = cnt;
    int ans = Chu_Liu();
    if (ans > (SUM<<1))
            cout << "impossible";
        else
        {
            int r;
            for (int i = 1; i <= n; ++i)
                if (fa[i] == fa[r])
                {
                    r = i;
                    break;
                }
            cout << ans-SUM << ' ' << r-1;
        }
    return 0;
}