#include <iostream>
#include <vector>
using namespace std;


const int K = 29;
const uint64_t MOD = 1e8 + 37;
string S, P;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> S >> P;
    if(P.size() > S.size()){
        cout << 0 << '\n';
        return 0;
    }
    
    uint64_t K_pow = 1;
    for(int i=1;i<P.size();++i)
        K_pow = (K_pow * K) % MOD;
    uint64_t p_val = 0;
    for(int i=0;i<P.size();++i)
        p_val = (p_val * K + P[i] - 96) % MOD;
    uint64_t s_val = 0;
    int ans = 0;
    for(int i=0;i<S.size();++i){
        if(i>=P.size())
            s_val = (s_val - ((S[i-P.size()]-96)*K_pow % MOD) + MOD) % MOD;
        s_val = (s_val * K + S[i]-96) % MOD;
        if(s_val == p_val)
            ++ans;
    }
    cout << ans << '\n';
    return 0;
}