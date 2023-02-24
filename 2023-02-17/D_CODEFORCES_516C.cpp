#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


const int64_t INF = 1e18;
const int MAX_N = 2e5+2;
struct E {
    int64_t mi;
    int64_t mx;
};
E Table[63][MAX_N];
int64_t s[2][MAX_N];
int K;
int calc(int a, int b, int c) {
    return s[c][a] > s[c][b] ? a : b;
}
void build() {
    for(int i=0;i<K;++i)
        Table[0][i].mi = Table[0][i].mx = i;
    int t = log2(K);
    for(int i=1;i<=t;++i) {
        for(int j=0;j+(1<<i)<=K;++j) {
            Table[i][j].mi = calc(Table[i - 1][j].mi, Table[i - 1][j + (1 << (i - 1))].mi, 0);
            Table[i][j].mx = calc(Table[i - 1][j].mx, Table[i - 1][j + (1 << (i - 1))].mx, 1);
        }
    }
}
int getMax(int l, int r) {
    int t = log2(r-l+1);
    return calc(Table[t][l].mx, Table[t][r-t+1].mx, 1);
}
int getMin(int l, int r) {
    int t = log2(r-l+1);
    return calc(Table[t][l].mi, Table[t][r-t+1].mi, 0);
}
int solve(int l, int r) {
    cout << "solve" << l << '\t' << r << '\n';
    int mip = getMin(l, r);
    int mxp = getMax(l, r);
    cout << "\t" << mxp << '\n';
    return s[1][mxp] + s[0][mip];
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> H(N), D(N);
    for(int &i: D) cin >> i;
    for(int &i: H) cin >> i;

    K = 2*N;
    vector<int64_t> preSum(K);
    for(int i=0;i<K;++i) {
        preSum[i] = D[i%N];
        if(i)
            preSum[i] += preSum[i-1];
    }

    for(int i=0;i<K;++i) {
        s[0][i] = -preSum[i] + H[i%N];
        s[1][i] = preSum[i] + H[i%N];
    }
    build();
    while(M--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(l <= r) {
            
            cout << solve(r+1, l-1+N) << '\n';
        }
    }
    return 0;
}
