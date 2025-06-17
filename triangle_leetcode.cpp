class Solution {
public:
    #define ll int
#define pb push_back

vector<vector<ll>> arr;
vector<vector<ll>> dp;
vector<vector<ll>> done;
ll n;

ll rec(ll r, ll c) {
    if (r < 0 || c < 0 || c>r) {
        return 1e9;
    }
    if (r == 0 && c == 0) {
        return arr[r][c];
    }

    if (done[r][c]) return dp[r][c];

    ll ans = 1e9;
    if (r != 0) {
        ans = min(ans, rec(r - 1, c) + arr[r][c]);
        if (c >= 1) {
            ans = min(ans, rec(r - 1, c - 1) + arr[r][c]);
        }
    }

    done[r][c] = 1;
    return dp[r][c] = ans;
}

    ll minimumTotal(vector<vector<ll>>& tri) {
         n=tri.size();
    arr.resize(n);
    dp.resize(n);
    done.resize(n);
    for (ll i = 1; i <= n; i++) {
        vector<ll> x(i);
        vector<ll> y(i, -1);
        vector<ll> z(i, 0);
        for (ll j = 0; j < i; j++) {
             x[j]=tri[i-1][j];
        }
        arr[i - 1] = x;
        dp[i - 1] = y;
        done[i - 1] = z;
    }

    ll ans = 1e9;
    for (ll j = 0; j < n; j++) {
        ans = min(ans, rec(n - 1, j));
    }
   return ans ;
    }
};