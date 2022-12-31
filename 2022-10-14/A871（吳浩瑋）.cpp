#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

#define int double
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

int N;
pii operator-(const pii &a, const pii &b)
{
    return mp(a.fi - b.fi, a.se - b.se);
}
int operator^(const pii &a, const pii &b)
{
    return a.fi * b.se - b.fi * a.se;
}
double A(const pii a, const pii b, const pii c)
{
    return ((b - a) ^ (c - a)) / 2;
}
void solve()
{
    vpii Points(N);
    for (pii &i : Points)
        cin >> i.fi >> i.se;
    sort(all(Points));
    vpii V;
    for (int i = 0; i < 2; ++i)
    {
        int T = V.size();
        for (pii point : Points)
        {
            while (V.size() - T >= 2 and ((V[V.size() - 1] - V[V.size() - 2]) ^ (point - V[V.size() - 2])) <= 0)
                V.pop_back();
            V.pb(point);
        }
        V.pop_back();
        reverse(all(Points));
    }
    double ans = 0;
    for (int i = 2; i < V.size(); ++i)
    {
        ans += A(V[0], V[i - 1], V[i]);
    }

    cout << setprecision(2) << fixed << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> N)
        solve();
    return 0;
}