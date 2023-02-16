#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 0x3f3f3f3f;
vector<vector<int> > Table(16, vector<int>(int(1e5)));
int query(int A, int B) {
    if(B<A)
        return -INF;
    if(A==B)
        return Table[0][A];
    int t = log2(B - A + 1);
    return max(Table[t][A], Table[t][B - (1 << t) + 1]);
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> H(N), D(N);
    for(int &i: D) cin >> i;
    for(int &i: H) cin >> i;

    int lg = log2(N);
    for(int i=0;i<N;++i)
        Table[0][i] = 2*(H[i]+H[(i+1)%N]) + D[i];
    for(int i=1;i<=1;++i) {
        for(int left=0;left+(1<<i)<=N;++left) {
            Table[i][left] = max(Table[i-1][left], Table[i-1][left+(1<<(i-1))]);
        }
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