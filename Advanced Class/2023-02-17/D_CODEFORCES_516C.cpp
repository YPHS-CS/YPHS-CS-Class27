#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


const int64_t INF = 1e18;
const int MAX_N = 2e5+4;
int64_t Table[63][MAX_N][2]; 
int64_t s[2][MAX_N];
int K;
int calc(int a, int b, int c) {
    return s[c][a] > s[c][b] ? a : b;
}
void build() {
    for(int i=0;i<K;++i)
        Table[0][i][0] = Table[0][i][1] = i;
    int t = log2(K);
    for(int i=1;i<=t;++i) {
        for(int j=0;j+(1<<i)<=K;++j) {
            Table[i][j][0] = calc(Table[i - 1][j][0], Table[i - 1][j + (1 << (i - 1))][0], 0);
            Table[i][j][1] = calc(Table[i - 1][j][1], Table[i - 1][j + (1 << (i - 1))][1], 1);
        }
    }
}
int getMax(int l, int r, int c) {
    if(l > r) return K;
    int t = log2(r-l+1);
    return calc(Table[t][l][c], Table[t][r-(1<<t)+1][c], c);
}
int64_t solve(int l, int r) {
    int mip = getMax(l, r, 0), mxp = getMax(l, r, 1);
    if(mip != mxp) return s[1][mxp] + s[0][mip];
    int mxpp = calc(getMax(l, mxp - 1, 1), getMax(mxp + 1, r, 1), 1);
    int mipp = calc(getMax(l, mxp - 1, 0), getMax(mxp + 1, r, 0), 0);
    return max(s[1][mxp] + s[0][mipp], s[1][mxpp] + s[0][mip]);
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
        preSum[i] = D[(i+N-1)%N];
        if(i)
            preSum[i] += preSum[i-1];
    }
    s[0][K] = s[1][K] = -INF;
    for(int i=0;i<K;++i) {
        s[0][i] = -preSum[i] + 2*H[i%N];
        s[1][i] = preSum[i] + 2*H[i%N];
    }
    build();
    while(M--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(l <= r) {
            cout << solve(r+1, l-1+N) << '\n';
        } else {
            cout << solve(r+1, l-1) << '\n';
        }
    }
    return 0;
}
