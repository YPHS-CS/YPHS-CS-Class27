#include <iostream>
#include <vector>
using namespace std;


const int INF = 0x3f3f3f3f;
int main() {
    int N, X;
    cin >> N >> X;
    vector<int> Nums(N);
    for(int &i: Nums) cin >> i;
    vector<int> dp(X+1, INF);
    dp[0] = 0;
    for(int i=0;i<N;++i) {
        for(int j=Nums[i];j<=X;++j) {
            dp[j] = min(dp[j-Nums[i]]+1, dp[j]);
        }
    }
    if(dp[X] != INF)
        cout << dp[X] << "\n";
    else
        cout << -1 << '\n';
    return  0;
}
