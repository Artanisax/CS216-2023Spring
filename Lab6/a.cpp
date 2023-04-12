#include <iostream>
#include <map>
#include <set>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef pair<int, int> pii;

const int K = 3e4+5;

map<int, int> cache;
set<pii> s;

int tim[K];

int main()
{
    IO_accel();
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 1; i <= m; i++)
    {
        if (!s.empty())
        {
            auto it = s.begin();
            if (i-(*it).first > t)
            {   
                cache.erase((*it).second);
                tim[(*it).second] = 0;
                s.erase(*it);
            }
        }
        int op, k, v;
        cin >> op;
        switch (op)
        {
            case 1:
                cin >> k;
                if (cache.count(k))
                {
                    auto it = s.find({tim[k], k});
                    cout << cache[k] << '\n';
                    s.erase(it);
                    tim[k] = i;
                    s.insert({i, k});
                }
                else
                    cout << "-1\n";
                break;
            
            case 2:
                cin >> k >> v;
                if (cache.count(k))
                {
                    auto it = s.find({tim[k], k});
                    s.erase(it);
                }
                cache[k] = v;
                tim[k] = i;
                s.insert({i, k});
                if (cache.size() > n)
                {
                    auto it = s.begin();
                    cache.erase((*it).second);
                    tim[(*it).second] = 0;
                    s.erase(*it);
                }
                break;
        }
    }
    for (auto it = s.begin(); it != s.end(); it++)
        cout << cache[(*it).second] << ' ';
    return 0;
}