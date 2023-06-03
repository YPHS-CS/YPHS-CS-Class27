#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

typedef pair<int64_t, int64_t> pii;
typedef vector<pair<int64_t, int64_t>> vpii;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

pii operator-(const pii &a, const pii &b)
{
    return mp(a.fi - b.fi, a.se - b.se);
}
int64_t operator^(const pii &a, const pii &b)
{
    return a.fi * b.se - b.fi * a.se;
}
int main()
{
    int N;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
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
    cout << V.size() << '\n';
    return 0;
}
