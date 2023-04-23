#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 4e3+5;

int s[N], v[N], w[N], dp[N], backup[N];
deque<int> q;

int main()
{
    IO_accel();
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> s[i] >> v[i] >> w[i];
    for (int i = 1; i <= n; i++)
    {
        memcpy(backup+1, dp+1, sizeof(int)*c);
        for (int j = 0; j < v[i]; j++)
        {
            q.clear();
            for (int k = j; k <= c; k += v[i])
            {
                if (!q.empty() && q.front()+s[i]*v[i] < k)
                    q.pop_front();
                if (!q.empty())
                    dp[k] = max(dp[k], backup[q.front()]+(k-q.front())/v[i]*w[i]);
                while (!q.empty() && (k-q.back())/v[i]*w[i] <= backup[k]-backup[q.back()])
                    q.pop_back();
                q.push_back(k);
            }
        }
    }
    cout << dp[c];
    return 0;
}