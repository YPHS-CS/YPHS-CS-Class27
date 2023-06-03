#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


const int INF = 0x3f3f3f3f;
int N, K;
vector<int > A, B, C;
int f(int t){
    vector<int >horse(N);
    for(int i=0;i<N;++i){
        uint64_t speed = A[i] + t * B[i];
        if(speed > (int)1e8)
            speed = (int)1e8 + 5;
        horse[i] = speed;
    }
    sort(horse.begin(), horse.end(), greater<int>());
    int cnt = 0, p = 0;
    for(int i:horse){
        while(p < N and i <= C[p])++p;
        if(p < N and i > C[p++]){
            ++cnt;
        }
        else break;
    }
    return cnt;
}
int binary_search(int l, int r){ // (]
    if(r - l <= 1)
        return r;
    int mid = l + (r - l) / 2;
    if(f(mid) >= K) return binary_search(l, mid);
    else return binary_search(mid, r);
}
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> N >> K;
        A.resize(N);
        B.resize(N);
        C.resize(N);
        for(int i=0;i<N;++i)
            cin >> A[i] >> B[i];
        for(int i=0;i<N;++i)
            cin >> C[i];
        sort(C.begin(), C.end(), greater<int>());
        int result = binary_search(-1, INF);
        if(result == INF)
            cout << -1 << '\n';
        else
            cout << result << '\n';
    }
    return 0;
}