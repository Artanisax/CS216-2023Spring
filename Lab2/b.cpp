#include <iostream>

using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    IO_accel();
    int n, k;
    cin >> n >> k;
    cout << (n == 1 ? 1 : (min(k, n-k+1)<<1));
    return 0;
}