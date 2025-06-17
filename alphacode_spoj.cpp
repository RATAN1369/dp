#include <bits/stdc++.h>
 
using namespace std;
 
int n;
int dp[1000100];
string s;
 
int rec(int level) {
  if (level == n) { 
    return 1;
  }
 
  if (dp[level] != -1) {
    return dp[level];
  }
 
  int ans = 0;
 
  // Interpret single digit
  if (s[level] != '0') { 
    ans += rec(level + 1);
  }
 
  // Interpret double digits
  if (level + 1 < n) {
    int num = (s[level] - '0') * 10 + (s[level + 1] - '0');
    if (num >= 10 && num <= 26) {
      ans += rec(level + 2);
    }
  }
 
  return dp[level] = ans;
}
 
void solve() {
  while (true) {
    cin >> s;
    n = s.size();
    memset(dp, -1, sizeof(dp));
 
    if (s == "0") {
      break;
    } else {
      cout << rec(0) << endl;
      s.clear();
    }
  }
}
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  solve();
  return 0;
}