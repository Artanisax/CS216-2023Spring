#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

const int N = 1e5+5, M = 1e6+5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct Edge
{
    int u, v;
    ll w, w0;

    Edge(int u, int v, ll w):
    	u(u), v(v), w(w), w0(w) {};
};

struct UnionFind
{
    int fa[N<<1] = {};

    int find(int x)
    { return fa[x] ? fa[x] = find(fa[x]) : x; }

    int operator[](int x)
    { return find(x); }
};

struct Node  // for leftist tree
{
    Edge *e;
    int dist, lazy;
    Node *lc, *rc;

    Node(Edge *e):
    	e(e), dist(0), lazy(0), lc(nullptr), rc(nullptr) {};

    void push() // push down the lazy tag
    {
        if (lc)  lc->lazy += lazy;
        if (rc)  rc->lazy += lazy;
        e->w += lazy;
        lazy = 0;
    }
};

// merge two leftist tree
Node *merge(Node *x, Node *y)
{
    if (!y)  return x;
    if (!x)  return y;
    if (x->e->w+x->lazy > y->e->w+y->lazy)
        swap(x, y);
    x->push();
    x->rc = merge(x->rc, y);
    if (!x->lc || x->lc->dist < x->rc->dist)
        swap(x->lc, x->rc);
    if (x->rc)  x->dist = x->rc->dist+1;
    else x->dist = 0;
    return x;
}

// get the minimal edge and delete the root
Edge *extract(Node *&x)
{
    Edge *ret = x->e;
    x->push();
    x = merge(x->lc, x->rc);
    return ret;
}

// fa[] record the contraction tree
int n, m, fa[N<<1], nxt[N<<1];
Edge *in[N<<1];
UnionFind id;
Node *tree[N<<1];
vector<Edge *> edge[N];

bool vis[N<<1];
void contract()
{
    // build leftist trees in O(m)
    for (int i = 1; i <= n; ++i)
    {
        queue<Node *>q;
        for (int j = 0; j < edge[i].size(); ++j)
            q.push(new Node(edge[i][j]));
        while (q.size() > 1)
        {
            Node *a, *b;
            a = q.front();
            q.pop();
            b = q.front();
            q.pop();
            q.push(merge(a, b));
        }
        tree[i] = q.front();
    }

    // start from an arbitrary vertex
    int s, t = 1, p;
    while (tree[t])
    {
        vis[t] = true;
        s = t;
        do
        {
            in[t] = extract(tree[t]);  // get the minimal edge
            t = id[in[t]->u];  // the super node u belongs to
        } while (t == s && tree[t]);  // till the path extends or no edge
        if (t == s)  break;  // the whole graph is contracted
        if (!vis[t])  continue;  // no loop found
        // contract the loop, update id[], fa[] and the lazy tag
        t = s;
        ++n;
        while (t != n)  // till all are merged the new super node
        {
            id.fa[t] = fa[t] = n;
            if (tree[t])  tree[t]->lazy -= in[t]->w;
            tree[n] = merge(tree[n], tree[t]);
            p = id[in[t]->u];  // the super node u belongs to
            nxt[p == n ? s : p] = t;  // record the loop
            t = p;
        }
    }
}

ll expand(int x, int r);

ll expand_loop(int x)
{
    ll ret = 0;
    for (int t = nxt[x]; t != x; t = nxt[t])
        if (in[t]->w0 == INF)
            return INF;
        else
            ret += expand(in[t]->v, t)+in[t]->w0;
    return ret;
}

ll expand(int x, int r)
{
    ll ret = 0;
    while (x != r)
    {
        ret += expand_loop(x);
        if (ret >= INF)  return INF;
        x = fa[x];
    }
    return ret;
}

int main()
{
    int r;
    cin >> n >> m >> r;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[v].push_back(new Edge(u, v, w));
    }
    // ensure the whole graph is strongly connected
    for (int i = 1; i < n; ++i)
        edge[i+1].push_back(new Edge(i, i+1, INF));
    contract();
    ll ans = expand(r, n); // enter from the true root
    printf("%lld", ans == INF ? -1 : ans);
    return 0;
}