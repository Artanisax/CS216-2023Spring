#include <bits/stdc++.h>
using namespace std;
const int N = 109, M = 10009;
struct edge
{
    int u, v, w;
} e[M]; // 用边表存储

int n, m, root, mn[N], fa[N], tp[N], lp[N], tot, ans;
int zl()
{
    while (1)
    {
        for (int i = 1; i <= n; i++)
            mn[i] = 1e9, fa[i] = tp[i] = lp[i] = 0;

        for (int i = 1, u, v, w; i <= m; i++) // Step 1
            if (e[i].u != e[i].v && (w = e[i].w) < mn[v = e[i].v])
                mn[v] = w, fa[v] = e[i].u;
        mn[root] = 0;
        for (int u = 1; u <= n; u++) // Step 2
        {
            ans += mn[u];
            if (mn[u] == 1e9)
                return -1;
        }

        for (int u = 1, v = 1; u <= n; u++, v = u) // Step 3
        {
            while (v != root && tp[v] != u && !lp[v])
                tp[v] = u, v = fa[v];
            if (v != root && !lp[v])
            {
                lp[v] = ++tot;
                for (int k = fa[v]; k != v; k = fa[k])
                    lp[k] = tot;
            }
        }
        if (!tot) // Step 4
            return ans;
        for (int i = 1; i <= n; i++) // Step 5
            if (!lp[i])
                lp[i] = ++tot;

        for (int i = 1; i <= m; i++) // Step 6
            e[i].w -= mn[e[i].v], e[i].u = lp[e[i].u], e[i].v = lp[e[i].v];
        n = tot, root = lp[root], tot = 0; // Step 7
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &root);
    for (int i = 1, u, v, w; i <= m; i++)
        scanf("%d%d%d", &u, &v, &w), e[i] = (edge){u, v, w};
    printf("%d", zl());
    return 0;
}