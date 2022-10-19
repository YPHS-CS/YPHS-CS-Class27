#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;


int main(){
    int N, M;
    cin >> N >> M;
    vector<int> nums(N), T(N);
    for(int i=0;i<M;++i){
        int l, r, w;
        cin >> l >> r >> w;
        nums[l-1] += w;
        nums[r] -= w;
    }
    for(int i=0;i<N;++i)
        cin >> T[i];
    for(int i=1;i<N;++i)
        nums[i] += nums[i-1];
    sort(nums.begin(), nums.end(), greater<int>());
    sort(T.begin(), T.end());
    uint64_t ans = 0;
    for(int i=0;i<N;++i){
        // cout << T[i] << ' ' << nums[i] << '\n';
        ans += nums[i] * T[i];
    }
    cout << ans << '\n';
    return 0;
}
