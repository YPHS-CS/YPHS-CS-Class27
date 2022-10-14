#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

int N, M;
vector<int> Father;
vector<pair<int, pii > > G;
void init() {
    Father.resize(N);
    for(int i=0;i<N;++i)
        Father[i] = i;
}
int find(int u) {
    if(Father[u] == u) {
        return u;
    }
    return Father[u] = find(Father[u]);
}
int main() {
    cin >> N >> M;
    init();
    for(int i=0;i<M;++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G.pb(mp(c, mp(a, b)));
    }
    sort(all(G));
    int cnt = 0;
    int cost = 0;
    for(auto i:G) {
        if(cnt == N-1)
            break;
        int fa = find(i.se.fi), fb = find(i.se.se);
        if(fa == fb) {
            continue;
        } else {
            Father[fa] = fb;
            ++cnt;
            cost += i.fi;
        }
    }
    cout << cost << '\n';
    return 0;
}
