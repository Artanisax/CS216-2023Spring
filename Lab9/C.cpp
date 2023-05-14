#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef long long ll;

ll n, ans, MOD;
ll dp[260][260], f1[260][260], f2[260][260];
int p[9] = {0,2,3,5,7,11,13,17,19};

struct Number
{
	ll val, big = -1, S;

	bool operator < (const Number &x) const {
		return big < x.big;
	}

	void init()
	{
		ll tmp = val;
		for (int i = 1; i <= 8; i++)
		{
			if (tmp%p[i] == 0)
                S |= (1<<i-1);
			while (tmp%p[i] == 0)
				tmp /= p[i];
		}
		if(tmp^1)
            big = tmp;
	}
} num[505];

ll mod(ll x)
{ return (x+MOD)%MOD; }

int main()
{
    IO_accel();
	cin >> n >> MOD;
	for(ll i = 2; i <= n; i++)
		num[i].val = i, num[i].init();
	sort(num+2, num+1+n);
	dp[0][0] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(i == 1 || num[i].big^num[i-1].big || !~num[i].big)
		{
			memcpy(f1, dp, sizeof(dp));
			memcpy(f2, dp, sizeof(dp));
		}
		for(int j = 255; ~j; j--)
			for(int k = 255; ~k; k--)
			{
				if(j&k)
                    continue;
				if(!(num[i].S&j))
                    f1[j][k|num[i].S] = mod(f1[j][k|num[i].S]+f1[j][k]);
				if(!(num[i].S&k)) 
                    f2[j|num[i].S][k] = mod(f2[j|num[i].S][k]+f2[j][k]);
			}
		if(i == n || num[i].big^num[i+1].big || !~num[i].big)
		{
			for (int j = 0;j <= 255; j++)
				for (int k = 0; k <= 255; k++)
				{
					if(j&k)
                        continue;
					dp[j][k] = mod(f1[j][k]+f2[j][k]-dp[j][k]);
				}
		}
	}
	for (int i = 0; i <= 255; i++)
		for (int j = 0; j <= 255; j++)
		{
			if (i&j)
                continue;
			ans = mod(ans+dp[i][j]);
		}
	cout << ans;
}