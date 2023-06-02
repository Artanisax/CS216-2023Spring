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

const int INF = 0x3f3f3f3f;
const int N = 1e2+5;

struct Edge
{
    int v,w;
} edge[N*N<<5];

int n, m, s, t, cnt, ans;
int dep[N], head[N], nxt[N*N<<5], now[N];

int id(int i, int j)
{ return (i-1)*n+j; }

void add(int u, int v, int w)
{
    cerr << "check: " <<  u << ' ' << v << ' ' << w << '\n';
    nxt[cnt] = head[u];
    head[u] = cnt;
    edge[cnt++] = (Edge){v, w};
}

bool bfs()
{
    memset(dep, -1, sizeof(int)*(n*m+2));
    memcpy(now, head, sizeof(int)*(n*m+2));
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
    cin >> n >> m;
    s = 0, t = n*m+1;
    memset(head, -1, sizeof(int)*(n*m+2));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int val;
            cin >> val;
            ans += val;
            if ((i^j)&1)
            {
                add(s, id(i, j), val);
                add(id(i, j), s, 0);
                if (i != 1)
                {
                    add(id(i, j), id(i-1, j), 0x3f3f3f3f);
                    add(id(i-1, j), id(i, j), 0);
                }
                if (i != n)
                {
                    add(id(i, j), id(i+1, j), 0x3f3f3f3f);
                    add(id(i+1, j), id(i, j), 0);
                }
                if (j != 1)
                {
                    add(id(i, j), id(i, j-1), 0x3f3f3f3f);
                    add(id(i, j-1), id(i, j), 0);
                }
                if (j != m)
                {
                    add(id(i, j), id(i, j+1), 0x3f3f3f3f);
                    add(id(i, j+1), id(i, j), 0);
                }
            }
            else
            {
                add(id(i, j), t, val);
                add(t, id(i, j), 0);
            }
        }
    while (bfs())
        ans -= dfs(s, INF-1);
    cout << ans;
    return 0;
}