#include <iostream>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 155, K = 25, MOD = 12345678;

int dp[N][N][K][K];

int main()
{
    IO_accel();
    int n, m, k;
    cin >> n >> m >> k;
    dp[0][0][0][0] = 1;
    for (int p = 0; p < n+m; p++)
        for (int r = 0; r <= min(p, n); r++)
        {
            int b = p-r;
            for (int i = 0; i <= k; i++)
                for (int j = 0; j <= k; j++)
                {
                    if (r != n)
                        dp[r+1][b][i+1][max(j-1, 0)] = (dp[r+1][b][i+1][max(j-1, 0)]+dp[r][b][i][j])%MOD;
                    if (b != m)
                        dp[r][b+1][max(i-1, 0)][j+1] = (dp[r][b+1][max(i-1, 0)][j+1]+dp[r][b][i][j])%MOD;
                }
        }
    int ans = 0;
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= k; j++)
            ans = (ans+dp[n][m][i][j])%MOD;
    cout << ans;
    return 0;
}