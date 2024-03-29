#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 1e3+5;

struct edge
{
    int u, v;
    double dist;

    static bool comp(edge &a, edge &b)
    { return a.dist < b.dist; }
} e[N*N];

int cnt, c[N];
int x[N], y[N];

int find(int u)
{ return  c[u] = (c[u] == u ? u : find(c[u])); }

int main()
{
    int n, k, t;
    cin >> n >> k;
    t = n;
    for (int i = 1; i <= n; ++i)
    {
        c[i] = i;
        cin >> x[i] >> y[i];
        for (int j = 1; j < i; ++j)
            e[++cnt] = (edge){i, j, sqrt(pow(x[i]-x[j], 2)+pow(y[i]- y[j], 2))};
    }
    sort(e+1, e+cnt+1, edge::comp);
    int id;
    for (id = 1; t > k; ++id)
        if (find(e[id].u) != find(e[id].v))
        {
            c[c[e[id].v]] = c[c[e[id].u]];
            --t;
        }
    for (; id <= cnt; ++id)
        if (find(e[id].u) != find(e[id].v))
        {
            cout << fixed << setprecision(2) << e[id].dist;
            break;
        }
    return 0;
}