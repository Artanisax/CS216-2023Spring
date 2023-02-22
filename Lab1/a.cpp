#include <iostream>
#include <queue>
#include <map>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 1e3+5;

int prefer[N][N], order[N][N], husband[N], idx[N];
string name[2][N];
map<string, int> id[2];
queue<int> q;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        id[1][s] = i;
        name[1][i] = s;
    }
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        id[0][s] = i;
        name[0][i] = s;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            string s;
            cin >> s;
            prefer[i][j] = id[0][s];
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            string s;
            cin >> s;
            order[i][id[1][s]] = j;
        }
    for (int i = 1; i <= n; ++i)
        q.push(i);
    while(!q.empty())
    {
        int m, w, h;
        m = q.front();
        q.pop();
        w = prefer[m][++idx[m]];
        h = husband[w];
        if (!h)  husband[w] = m;
        else
        {
            if (order[w][m] < order[w][h])
            {
                q.push(h);
                husband[w] = m;
            }
            else
                q.push(m);
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << name[1][husband[i]] << ' ' << name[0][i] << '\n';
    return 0;
}