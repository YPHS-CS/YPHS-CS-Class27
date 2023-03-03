#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  string s; cin >> s;

  int n = s.length();
  vector<int> cnt(10);
  for(int i = 0; i < n; i++) cnt[s[i] - '0']++;
  for(int i = 0; i < 10; i++) if(cnt[i] >= 1000) {
    for(int j = 0; j < 1000; j++) cout << i;
    cout << '\n';
    return 0;
  }

  assert(n <= 10000);
  vector<vector<int>> dp(n, vector<int>(n));
  for(int i = 0; i < n; i++) dp[i][i] = 1;
  for(int len = 1; len < n; len++) {
    for(int l = 0; l + len < n; l++) {
      int r = l + len;
      if(s[l] == s[r]) dp[l][r] = dp[l + 1][r - 1] + 2;
      else dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
    }
  }

  bool flag = 0;
  int l = 0, r = n - 1;
  string ans;
  while(l <= r) {
    if(l == r) {flag = 1; ans += s[l]; break;}
    else if(s[l] == s[r] && dp[l][r] == dp[l + 1][r - 1] + 2) ans += s[l++], r--;
    else if(dp[l][r] == dp[l + 1][r]) l++;
    else r--;
  }
  cout << ans;
  if(flag) ans.pop_back();
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
  return 0;
}