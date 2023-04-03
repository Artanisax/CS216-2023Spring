#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;

const int N = 1e3 + 5, M = 1e4 + 5;
const ll SUM = 1e7, INF = 1e17;

int id[N], vis[N], pre[N], pos;
ll in[N];
struct node
{
    int u, v, w;
} edge[M + N];

ll zhuliu(int root, int V, int E)
{
    ll res = 0;
    while (true)
    {
        for (int i = 0; i < V; i++)
            in[i] = INF;
        for (int i = 0; i < E; i++)
        {
            int u = edge[i].u, v = edge[i].v;
            if (u != v && in[v] > edge[i].w)
            {
                in[v] = edge[i].w;
                pre[v] = u;
                if (u == root)
                    pos = i;
            }
        }
        for (int i = 0; i < V; i++)
            if (in[i] == INF && i != root)
                return -1;
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        int cnt = 0;
        in[root] = 0;
        for (int i = 0; i < V; i++)
        {
            int v = i;
            res += in[i];
            while (id[v] == -1 && vis[v] == -1 && v != root)
            {
                vis[v] = i;
                v = pre[v];
            }
            if (id[v] == -1 && v != root && vis[v] == i)
            {
                for (int u = pre[v]; u != v; u = pre[u])
                    id[u] = cnt;
                id[v] = cnt++;
            }
        }
        if (!cnt)
        {
            break;
        }
        for (int i = 0; i < V; i++)
        {
            if (id[i] == -1)
            {
                id[i] = cnt++;
            }
        }
        for (int i = 0; i < E; i++)
        {
            int u = edge[i].u, v = edge[i].v;
            edge[i].u = id[u];
            edge[i].v = id[v];
            if (id[u] != id[v])
            {
                edge[i].w -= in[v];
            }
        }
        V = cnt;
        root = id[root];
    }
    return res;
}

int main()
{
    int n, m;
    while (~scanf("%d %d", &n, &m))
    {
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
            edge[i].u++, edge[i].v++;
        }
        for (int i = m; i < n + m; i++)
        {
            edge[i].u = 0;
            edge[i].v = i - m + 1;
            edge[i].w = SUM;
        }
        ll res = zhuliu(0, n + 1, n + m);
        if (res == -1 || res >= SUM<<1)
        {
            puts("impossible");
        }
        else
        {
            printf("%lld %d\n", res - SUM, pos - m);
        }
        putchar('\n');
    }
}