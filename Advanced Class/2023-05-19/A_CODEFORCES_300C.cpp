#include <iostream>
#include <vector>
using namespace std;


const int MAX_N = 1e6 + 5;
const int MOD = 1e9 + 7;
int A, B, N;
vector<uint64_t> fact(MAX_N);
uint64_t qpow(uint64_t x, uint64_t u) {
    uint64_t ans = 1;
    while(u) {
        if(u & 1)
            ans = ans * x % MOD;
        x = x * x % MOD;
        u >>= 1;
    }
    return ans;
}
inline uint64_t inv(uint64_t x) {
    return qpow(x, MOD - 2);
}
inline uint64_t C(uint64_t a, uint64_t b) {
    return fact[a] * inv(fact[b]) % MOD * inv(fact[a-b]) % MOD;
}
bool is_good_number(uint64_t x) {
    while(x) {
        if(x%10 != A and x%10 != B)
            return false;
        x /= 10;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B >> N;
    fact[0] = 1;
    for(int i=1;i<=N;++i)
        fact[i] = (fact[i-1]*i) % MOD;

    uint64_t ans = 0; 
    for(int i=0;i<=N;++i) {
        int aux = A*i + B*(N-i);
        if(is_good_number(aux)) {
            ans = (ans + C(N, i)) % MOD;
        }
    }
    cout << ans << '\n';
    return 0;
}
