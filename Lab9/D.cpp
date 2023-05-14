#include <iostream>
#include <climits>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 5e3+5;

int dp[N][N];

int main()
{
    IO_accel();
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int i = 0; i < n-1; i++)
        dp[i][i+1] = 1+(s[i] != s[i+1]);
    for (int len = 3; len <= n; len++)
        for (int l = 0; l < n-len+1; l++)
        {
            int r = l+len-1;
            dp[l][r] = INT_MAX;
            for (int k = l; k < r; k++)
                dp[l][r] = min(dp[l][r], dp[l][k]+dp[k+1][r]);
            dp[l][r] -= (s[l] == s[r]);
        }
    cout << dp[0][n-1];
    return 0;
}