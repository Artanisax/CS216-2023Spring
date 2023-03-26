#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef pair<double, int> pdi;

const int N = 1e3+5;

int ans;
struct Node
{
    int id, c, fa, cc, sum, cnt, next, last;
    bool vis;
} node[N];
priority_queue<pdi> q;

int find(int x)
{
    return node[x].cc = (node[x].cc == x ? x : find(node[x].cc)); 
}

void init()
{
    ans = 0;
    memset(node, 0, sizeof(node));
}

int main()
{
    while (true)
    {
        int n, rt;
        cin >> n >> rt;
        if (!n && !rt)
            break;
        init();
        for (int i = 1; i <= n; ++i)
        {
            cin >> node[i].c;
            node[i].id = node[i].cc = node[i].last = i;
            node[i].sum = node[i].c;
            node[i].cnt = 1;
            if (i != rt)
                q.push(make_pair(node[i].c, i));
        }
        for (int i = 1; i < n; ++i)
        {
            int x, y;
            cin >> x >> y;
            node[y].fa = x;
        }
        while (!q.empty())
        {
            int id = q.top().second;
            q.pop();
            if (node[id].vis)
                continue;
            node[id].vis = true;
            int f = node[id].fa;
            if (node[f].vis)
                f = find(f);
            node[f].sum += node[id].sum;
            node[f].cnt += node[id].cnt;
            node[node[f].last].next = id;
            node[f].last = node[id].last;
            node[id].cc = f;
            if (f != rt)
                q.push(make_pair((double)node[f].sum/node[f].cnt, f));
        }
        for (int i = 1, id = rt; i <= n; ++i, id = node[id].next)
            ans += i*node[id].c;
        cout << ans << '\n';
    }
    return 0;
}