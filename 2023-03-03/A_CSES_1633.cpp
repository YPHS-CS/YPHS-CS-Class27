#include <iostream>
#include <vector>
using namespace std;


const int MAX_N = 1e6;
const int MOD = 1e9+7;
int main() {
    vector<int> dp(MAX_N + 6);
    dp[0] = 1;
    for(int i=0;i<MAX_N;++i) {
        for(int j=1;j<=6;++j) {
            dp[i+j] += dp[i];
            dp[i+j] %= MOD;
        }
    }
    
    int N;
    cin >> N;
    cout << dp[N] << '\n';
    return 0;
}
