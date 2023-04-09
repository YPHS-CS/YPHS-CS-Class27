#include <iostream>
#include <vector>
using namespace std;
#define A first
#define B second

const int MAX_N = 1e5 + 5;
const int MOD = 1e9 + 7;
vector<int> G[MAX_N];
pair<int, int> bfs(int u=1, int prv=-1) {
    pair<uint64_t, uint64_t> ans(1, 1);
    for(int i=0;i<G[u].size();++i) {
        if(G[u][i] == prv)
            continue;
        auto result = bfs(G[u][i], u);
        ans.A = ans.A * ((result.A + result.B) % MOD) % MOD;
        ans.B = ans.B * (result.A % MOD) % MOD;
    }
    return ans;
}
int main() {
    int N;
    cin >> N;
    for(int X, Y, i=1;i<N;++i) {
        cin >> X >> Y;
        G[X].push_back(Y);
        G[Y].push_back(X);
    }
    auto result = bfs();
    cout << (result.A + result.B ) % MOD << '\n';
    return 0;
}
