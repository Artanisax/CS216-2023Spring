#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef pair<int, int> pii;

const int N = 1e3+5;

int cap[N], c[N][N], id[N];
pii s[N][N];
queue<int> q;
priority_queue<pii, vector<pii>, greater<pii>> enroll[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> cap[i];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            s[i][j].second = j;
            cin >> s[i][j].first;
        }
        sort(s[i]+1, s[i]+m+1, greater<pii>());
    }
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> c[i][j];
    for (int i = 1; i <= n; ++i)
        q.push(i);
    while (!q.empty())
    {
        int stu, col;
        stu = q.front();
        q.pop();
        col = s[stu][++id[stu]].second;
        if (enroll[col].size() < cap[col])
            enroll[col].push(make_pair(c[col][stu], stu));
        else
            if (c[col][stu] > enroll[col].top().first)
            {
                q.push(enroll[col].top().second);
                enroll[col].pop();
                enroll[col].push(make_pair(c[col][stu], stu));
            }
            else q.push(stu);
    }
    for (int i = 1; i <= m; ++i)
    {
        cout << enroll[i].size() << ' ';
        while (!enroll[i].empty())
        {
            cout << enroll[i].top().second << ' ';
            enroll[i].pop();
        }
        cout << '\n';
    }
    return 0;
}