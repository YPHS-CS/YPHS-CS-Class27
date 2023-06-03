#include<iostream>
#include<set>
using namespace std;


const int MAX_N = 2e5 + 2;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;
    int arr [MAX_N];
    for (int i = 0;i < N;i++) {
        int a, b;
        cin >> a >> b;
        arr [b - 1] = a;
    }
    uint64_t ans = 0;
    set<int>s;
    s.insert(0);
    s.insert(L);
    for (int i = 0;i < N;i++) {
        ans += *(s.upper_bound(arr[i])) - *(prev(s.upper_bound(arr [i])));
        s.insert(arr [i]);
    }
    cout << ans << endl;
    return 0;
}
