#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 2e2+5, M = 2e4+5;

struct Edge
{
    int v, w;
} edge[M<<1];

int n, m, s, t, k, cnt, ans;
int dep[N], head[N], nxt[M<<1], now[N];

void add(int u, int v, int w)
{
    nxt[cnt] = head[u];
    head[u] = cnt;
    edge[cnt++] = (Edge){v, w};
}

bool bfs()
{
    memset(dep, -1, sizeof(int)*n);
    memcpy(now, head, sizeof(int)*n);
    dep[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = nxt[i])
        {
            int v = edge[i].v, w = edge[i].w;
            if (!w || ~dep[v])
                continue;
            dep[v] = dep[u]+1;
            q.push(v);
        }
    }
    return ~dep[t];
}

int dfs(int u, int limit)
{
    if (u == t)
        return limit;
    int ret = 0;
    for (int i = now[u]; ~i && limit; i = nxt[i])
    {
        now[u] = i;
        int v = edge[i].v, w = edge[i].w;
        if (!w || dep[v] != dep[u]+1)
            continue;
        int flow = dfs(v, min(limit, w));
        edge[i].w -= flow;
        edge[i^1].w += flow;
        limit -= flow;
        ret += flow;
    }
    return ret;
}

int main()
{
    IO_accel();
    cin >> n >> m >> k;
    t = n++;
    memset(head, -1, sizeof(int)*n);
    for (int i = 1; i <= k; i++)
    {
        int girl;
        cin >> girl;
        add(girl, t, 1);
        add(t, girl, 0);
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v, 1);
        add(v, u, 1);
    }
    while (bfs())
        ans += dfs(s, INT_MAX);
    cout << ans;
    return 0;
}