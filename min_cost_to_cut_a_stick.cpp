class Solution {
public:
    vector<int> pos;
    int dp[105][105];
    int done[105][105];

    int rec(int l, int r) {
        if (l + 1 >= r) return 0;
        if (done[l][r]) return dp[l][r];

        int ans = 1e9;
        for (int i = l + 1; i < r; i++) {
            ans = min(ans, rec(l, i) + rec(i, r) + (pos[r] - pos[l]));
        }

        done[l][r] = 1;
        return dp[l][r] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        pos = cuts;
        memset(dp, 0, sizeof(dp));
        memset(done, 0, sizeof(done));

        int sz = pos.size();
        return rec(0, sz - 1);
    }
};
