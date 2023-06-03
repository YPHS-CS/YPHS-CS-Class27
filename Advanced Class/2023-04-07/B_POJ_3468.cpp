#include <iostream>
#include <vector>
using namespace std;


const int MAX_N = 1e5 + 5;
vector<int64_t> lazyTag(4*MAX_N), total(4*MAX_N);
void push(int u, int lb, int rb) {
    if(lazyTag[u] == 0) return;
    int mid = (lb+rb) / 2;
    lazyTag[2*u] += lazyTag[u];
    lazyTag[2*u+1] += lazyTag[u];
    total[2*u] += (mid-lb+1)*lazyTag[u];
    total[2*u+1] += (rb-mid)*lazyTag[u];
    lazyTag[u] = 0;
}
void update(int u, int x, int l, int r, int lb, int rb) {
    // cout << "update\t" << u << ' ' << x << '\t' << l << '\t' << r << '\n';
    
    if(l <= lb and rb <= r) {
        lazyTag[u] += x;
        total[u] += (rb-lb+1) * x;
    // cout << "TOTAL" << u << ' ' << total[u] << '\n';
        return;
    }
    push(u, lb, rb);
    int mid = (lb+rb) / 2;
    if(l <= mid) update(2*u, x, l, r, lb, mid);
    if(mid+1 <= r) update(2*u+1, x, l, r, mid+1, rb);
    total[u] = total[2*u] + total[2*u+1];
    // cout << "TOTAL" << u << ' ' << total[u] << '\n';
}
int64_t query(int u, int l, int r, int lb, int rb) {
    // cout << "query\t" << u << ' ' << l << '\t' << r << '\t' << lb << '\t' << rb << '\n';
    // cout << "total[" << u << "]: " << total[u] << '\n';
    if (l <= lb and rb <= r){
        return total[u];
    }
    int mid = (lb+rb) / 2;
    int64_t ret = 0;
    push(u, lb, rb);
    if(l <= mid) ret += query(2*u, l, r, lb, mid);
    if(mid+1 <= r) ret += query(2*u+1, l, r, mid+1, rb);
    return ret;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    for(int x, i=1;i<=N;++i) {
        cin >> x;
        update(1, x, i, i, 1, N);
    }
    int a, b, c;
    char C;
    while(Q--) {
        cin >> C;
        if(C == 'C') {
            cin >> a >> b >> c;
            update(1, c, a, b, 1, N);
        } else {
            cin >> a >> b;
            cout << query(1, a, b, 1, N) << '\n';
        }
    }
    return 0;
}