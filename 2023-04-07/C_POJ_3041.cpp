#include <iostream>
#include <vector>
using namespace std;

#define eb push_back

const int MAX_N = 505;
int N, K;
vector<int> G[2*MAX_N];
vector<bool> visited(2*MAX_N);
vector<int> connection(2*MAX_N, -1);
bool dfs(int u) {
    visited[u] = true;
    for(int i=0;i<G[u].size();++i) {
        int &v = G[u][i], &w = connection[v];
        if(connection[v] == -1 or (!visited[w] and dfs(w))) {
            connection[v] = u;
            connection[u] = v;
            return true;
        }
    }
    return false;
}
int solve() {
    int ans = 0;
    for(int i=1;i<=2*N;++i) {
        if(connection[i] == -1) {
            visited.assign(2*N+1, false);
            if(dfs(i)) {
                ++ ans;
            }
        }
    }
    return ans;
}
int main() {
    cin >> N >> K;
    for(int a, b, i=0;i<K;++i) {
        cin >> a >> b;
        int na = a, nb = N+b;
        G[na].eb(nb);
        G[nb].eb(na);
    }
    cout << solve() << '\n';
    return 0;
}
