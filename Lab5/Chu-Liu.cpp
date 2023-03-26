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

const int N = 1e2+5;

int n, m, r, fa[N], mini[N];
vector<pii> edge[N];

int find()
{}

int Chu_Liu()
{
    int u, v, w, ans = 0;
    while (true)
    {
        for (int i = 1; i <= n; ++i)
        {
            fa[i] = 0;
            mini[i] = INT_MAX;
        }
        for (int u = 1; u <= n; ++u)
            for (int i  = 0; i < edge[u].size(); ++i)
            {
                v = edge[u][i].first;
                w = edge[u][i].second;
                if (u!= v && w < mini[v])
                {
                    mini[v] = w;
                    fa[v] = u;
                }
            }
        mini[r] = fa[r] = 0;
        for (int i =1; i <= n; ++i)
        {
            if (mini[i] == INT_MAX)
                return -1;
            ans += mini[i];
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m >> r;
    int u, v, w;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u, v, w;
        edge[u].push_back(make_pair(v, w));
    }
    cout << Chu_Liu();
    return 0;
}