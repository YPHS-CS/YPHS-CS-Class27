#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;


const int MAX_N = 1e4+2;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> primeNumber;
    vector<bool> isPrimeNumber(MAX_N, true);
    for(int i=2;i<MAX_N;++i) {
        if(isPrimeNumber[i]) {
            primeNumber.push_back(i);
            for(int j=2;i*j<MAX_N;++j) {
                isPrimeNumber[i*j] = false;
            }
        }
    }

    vector<int> preSum(primeNumber.size());
    set<int> preSumSet;
    for(int i=0;i<primeNumber.size();++i) {
        preSum[i+1] = primeNumber[i] + preSum[i];
    }
    for(int i=0;i<preSum.size();++i) {
        preSumSet.insert(preSum[i]);
    }

    int N;
    while(cin >> N and N) {
        int ans = 0;
        for(int i=0;i<primeNumber.size();++i) {
            if(N < primeNumber[i])
                break;
            if(preSumSet.find(preSum[i]+N)!=preSumSet.end()) {
                ++ans;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}