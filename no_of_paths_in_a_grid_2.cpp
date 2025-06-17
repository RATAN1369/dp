#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, m, k;
int arr[201][201];
int dp[201][201][401];

int rec(int r, int c, int k) {
    if (r < 0 || c < 0 || k < 0) return 0;

    if (arr[r][c] == 1 && k == 0) return 0;  // Can't enter a blocked cell without conversions left

    if (r == 0 && c == 0)
        return (arr[0][0] == 1 && k >= 1) || (arr[0][0] == 0) ? 1 : 0;

    if (dp[r][c][k] != -1) return dp[r][c][k];

    int cost = arr[r][c];
    int ans = 0;

    if (r > 0) ans = (ans + rec(r - 1, c, k - cost)) % MOD;
    if (c > 0) ans = (ans + rec(r, c - 1, k - cost)) % MOD;

    return dp[r][c][k] = ans;
}

void solve() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int x = 0; x <= k; ++x)
                dp[i][j][x] = -1;

    cout << rec(n - 1, m - 1, k) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
