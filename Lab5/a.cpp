#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#include <utility>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef pair<int, int> pii;     // (pos, h)
typedef pair<int, string> pis;  // (dist, state)

const char init[5][5] = {"11111",
                         "01111",
                         "00*11",
                         "00001",
                         "00000"};
const int mv[2][8] = {{-2, -1,  1, 2, 2, 1, -1, -2}, {1, 2, 2, 1, -1, -2, -2, -1}};

string goal;

pii get_info(const string &s)
{
    int pos, h = -1;
    for (int i = 0; i < 25; ++i)
    {
        if (s[i] == '*')
            pos = i;
        if (s[i] != goal[i])
            ++h;
    }
    return make_pair(pos, h);
}

bool dfs(int x, int y)
{

}

int main()
{
    IO_accel();
    int T;
    cin >> T;
    while (T--)
    {
        int pos, h, d, ans = -1;
        string s;
        pii info;
        goal.clear();

        for (int i = 0; i < 5; ++i)
        {
            cin >> s;
            goal += s;
        }
        info = get_info(init);

        queue<pis> q;
        q.push(make_pair(0, init));
        dfs();
        cout << ans << '\n';
    }
    return 0;
}