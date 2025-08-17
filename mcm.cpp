#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[105][105];
int backMat[105][105];
ll x[105], y[105];
int opb[105], clb[105];
int n;

ll rec(int l, int r){
    if(l >= r) return 0;
    ll &res = dp[l][r];
    if(res != -1) return res;
    res = (1LL<<62);
    int best = -1;
    for(int mid = l; mid < r; ++mid){
        ll cand = rec(l, mid) + rec(mid+1, r) + x[l]*y[mid]*y[r];
        if(cand < res){
            res = cand;
            best = mid;
        }
    }
    backMat[l][r] = best;
    return res;
}

void generate(int l, int r){
    if(l >= r) return;
    opb[l]++; clb[r]++;
    int mid = backMat[l][r];
    generate(l, mid);
    generate(mid+1, r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> x[i];
    for(int i = 0; i < n; ++i) cin >> y[i];

    memset(dp, -1, sizeof(dp));
    rec(0, n-1);          // fill dp and backMat
    generate(0, n-1);     // compute parentheses counts

    vector<string> t;
    t.reserve(n);
    for(int i = 0; i < n; ++i){
        string s;
        s.append(opb[i], '(');
        s += to_string(i+1);
        s.append(clb[i], ')');
        t.push_back(move(s));
    }
    for(int i = 0; i < n; ++i){
        if(i) cout << ' ';
        cout << t[i];
    }
    cout << '\n';
}
