#include <iostream>
#include <vector>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 1e3+5;

int c[N], siz[N];
vector<int> edge[N];

int dfs(int u)
{
    int ret = 0;
    siz[u] = c[u];
    for (int v : edge[u])
    {
        if (v == u)  continue;
        
    }
}

int main()
{
    int n, rt;
    cin >> n >> rt;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    
    return 0;
}