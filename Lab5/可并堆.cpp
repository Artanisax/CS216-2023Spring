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

const int N = 1e5+5, M = 1e5+5;

struct Node
{
    int val, dist, lc, rc, fa;
} node[N];

int find(int x)
{ return node[x].fa = (node[x].fa == x ? x : find(node[x].fa)); }

int merge(int x, int y)
{
    // if (!x || !y)
    //     return x|y;
    // if (node[x].val > node[y].val)
    //     swap(x, y);
    // node[find(node[y].fa)].fa = find(node[x].fa);
    // node[x].rc = merge(node[x].rc, y);
    // if (node[node[x].lc].dist < node[node[x].rc].dist)
    //     swap(node[x].rc, node[x].rc);
    // ++node[x].dist;
    return x;
}

int main()
{
    int n, m, op, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> node[i].val;
    while (m--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y;
            merge(x, y);
        }
        else
        {
            cin >> x;
            cout << node[find(x)].val << '\n';
        }
    }
    return 0;
}