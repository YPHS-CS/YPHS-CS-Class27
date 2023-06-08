#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

#define int long long
#define ld long double

#ifdef ONLINE_JUDGE
#define settings()                                                             \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0)
#elif defined(sublime)
#include <cstdio>
#define settings()                                                             \
  freopen("file.in", "r",                                                      \
          stdin) // Because Sublime Text doesn't support input from terminal.
#else
#define settings()
#endif

#define INF INT64_MAX / 100
#define all(x) x.begin(), x.end()

#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cerr << #x << " = " << x << '\n'
#endif

#ifdef ONLINE_JUDGE
#define debug_all(x)
#else
#define debug_all(x)                                                           \
  {                                                                            \
    cerr << #x << ": ";                                                        \
    for (auto i : x)                                                           \
      cerr << i << ' ';                                                        \
    cerr << '\n';                                                              \
  }
#endif

#ifdef ONLINE_JUDGE
#define debug_enter()
#else
#define debug_enter() cerr << "\n";
#endif

#define v vector
#define vi v<int>
#define vvi v<vi>

#define lowbit(x) (x) & (-x)

#define pb push_back
#define eb emplace_back

#define setpoint(x) fixed << setprecision(x)

const double eps = 1e-9;

int n;

struct p {
  int _x, _y, _z, _i;
  p(int x = 0, int y = 0, int z = 0, int i = 0) : _x(x), _y(y), _z(z), _i(i) {}
};

v<p> arr;
vi bit, ans;

void add(int x, int va) {
  while (x <= n) {
    bit[x] += va;
    x += lowbit(x);
  }
}

int sum(int x) {
  int ret = 0;
  while (x > 0) {
    ret += bit[x];
    x -= lowbit(x);
  }
  return ret;
}

void merge(int l, int r) {
  if (l + 1 == r)
    return;
  int m = l + (r - l) / 2;
  stack<pair<int, int>> st;
  queue<p> q;
  merge(l, m);
  merge(m, r);
  int a = l, b = m;
  while (a < m || b < r) {
    if (a < m && (b >= r || arr[a]._y > arr[b]._y)) {
      add(arr[a]._z, 1);
      st.push(make_pair(arr[a]._z, -1));
      q.push(arr[a++]);
    } else {
      ans[arr[b]._i] += sum(n) - sum(arr[b]._z);
      q.push(arr[b++]);
    }
  }
  while (!st.empty()) {
    add(st.top().first, st.top().second);
    st.pop();
  }
  for (int i = l; i < r; ++i) {
    arr[i] = q.front();
    q.pop();
  }
}

signed main() {
  settings();
  cin >> n;
  arr.resize(n);
  bit.resize(n + 1);
  ans.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i]._x >> arr[i]._y >> arr[i]._z;
    arr[i]._i = i;
  }
  sort(all(arr), [](p a, p b) {
    if (a._x == b._x && a._y == b._y)
      return a._z < b._z;
    else if (a._x == b._x)
      return a._y < b._y;
    return a._x > b._x;
  });
  merge(0, n);
  for (auto i : ans)
    cout << i << '\n';
  return 0;
}