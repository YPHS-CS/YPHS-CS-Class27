#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


const int INF = 1e18;
vector<int, vector<uint64_t> > build(uint64_t V) {
    int t = log2(V.size());
    vector<int, vector<uint64_t> > RET(t, vector<uint64_t>(V.size()));
    RET[0] = V;
    for(int i=1;i<=t);++i) {
        for(int left=0;left+(1<<i)<=N;++left) {
            Table[i][left] = max(Table[i-1][left], Table[i-1][left+(1<<(i-1))]);
        }
    }
    return RET;
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> H(N), D(N);
    for(int &i: D) cin >> i;
    for(int &i: H) cin >> i;
    int K = 2*N;

    vector<uint64_t> preSum(K);
    for(int i=0;i<K;++i) {
        preSum[i] = D[i%N];
        if(i)
            preSum[i] += preSum[i-1];
    }

    vector<uint64_t> vLeft(K), vRight(K);

    for(int i=0;i<K;++i) {
        vLeft[i] = -preSum[i] + H[i%N];
        vRight[i] = preSum[i] + H[i%N];
    }


    for(int i=0;i<M;++i) {
        int A, B;
        int ans;
        cin >> A >> B;
        A--, B--;
        if(A <= B) {
            cout << max(query(0, A - 2), query(B+1, N-1-(A==0))) << '\n';
        } else {
            cout << query(B, A-2) << '\n';
        }
    }
    return 0;
}
