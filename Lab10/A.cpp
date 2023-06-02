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

typedef long long ll;

const int N = 2e2+5, M = 5e3+5;

struct Edge
{
    int v;
    ll w;
}edge[M<<1];

int n, m, s, t, cnt;
int dep[N], head[N], nxt[M<<1], now[N];
ll ans;

void add(int u, int v, ll w)
{
    nxt[cnt] = head[u];
    head[u] = cnt;
    edge[cnt++] = (Edge){v, w};
}

bool bfs()
{
    memset(dep+1, -1, sizeof(int)*n);
    memcpy(now+1, head+1, sizeof(int)*n);
    dep[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = nxt[i])
        {
            int v = edge[i].v;
            ll w = edge[i].w;
            if (!w || ~dep[v])
                continue;
            dep[v] = dep[u]+1;
            q.push(v);
        }
    }
    return ~dep[t];
}

ll dfs(int u, ll limit)
{
    if (u == t)
        return limit;
    ll ret = 0;
    for (int i = now[u]; ~i && limit; i = nxt[i])
    {
        now[u] = i;
        int v = edge[i].v;
        ll w = edge[i].w;
        if (!w || dep[v] != dep[u]+1)
            continue;
        ll flow = dfs(v, min(limit, w));
        edge[i].w -= flow;
        edge[i^1].w += flow;
        limit -= flow;
        ret += flow;
    }
    return ret;
}

int main()
{
    cin >> n >> m >> s >> t;
    memset(head+1, -1, sizeof(int)*n);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
    }
    while (bfs())
        ans += dfs(s, LONG_LONG_MAX);
    cout << ans;
    return 0;
}