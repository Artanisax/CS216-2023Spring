#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <utility>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef pair<int, int> pii;

const double EPS = 1e-4;
const int N = 7e3+5;
const int M = 2e4+5;

int cnt, head[N];
double ans, dis[N];
bool vis[N];
struct Edge
{
    int v, w, p, nxt;
}edge[M];

void add(int u, int v, int w)
{
    edge[++cnt] = (Edge){v, w, 0, head[u]};
    head[u] = cnt;
}

bool spfa(int u)
{
    if (vis[u])
        return false;
    vis[u] = true;
    for (int i = head[u]; i; i = edge[i].nxt)
    {
        Edge e = edge[i];
        int v = e.v, w = e.w, p = e.p;
        double nw = ans*p-w;
        if (dis[u]+nw < dis[v])
        {
            dis[v] = dis[u]+nw;
            if (!spfa(v))
                return false;
        }
    }
    vis[u] = false;
    return true;
}

int main()
{
    IO_accel();
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w, p;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    for (int i = 1; i <= m; i++)
    {
        int p;
        cin >> p;
        edge[i].p = p;
    }
    for (int i = 1; i <= n; i++)
        add(0, i, 0);
    double l = 0, r = 200;
    while (r-l > EPS)
    {
        for (int i = 1; i <= n; i++)
        {
            dis[i] = 1e20;
            vis[i] = false;
        }
        vis[0] = false;
        ans = (l+r)/2;
        if (spfa(0))
            r = ans;
        else
            l = ans;
    }
    if (ans < EPS) cout << -1;
    else cout << fixed << setprecision(1) << ans;
    return 0;
}