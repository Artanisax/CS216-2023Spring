#include <iostream>
#include <vector>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef long long ll;

const int N = 1e5+5;

int v[N], fa[N];
ll cnt[N][2];
vector<int> edge[N];

void dfs(int u)
{
    for (int v : edge[u])
    {
        if (v == fa[u])
            continue;
        fa[v] = u;
        dfs(v);
        cnt[u][0] = max(cnt[u][0], cnt[v][0]);
        cnt[u][1] = max(cnt[u][1], cnt[v][1]);
    }
    v[u] += cnt[u][0]-cnt[u][1];
    if (v[u] > 0)
        cnt[u][1] += v[u];
    else
        cnt[u][0] -= v[u];
}

int main()
{
    IO_accel();
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    dfs(1);
    cout << cnt[1][0]+cnt[1][1];
    return 0;
}