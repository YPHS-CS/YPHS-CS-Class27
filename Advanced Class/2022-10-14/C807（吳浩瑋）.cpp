#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define all(x) x.begin(), x.end()

map<int, pair<int, int> > MP;
set<int> ST;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int c, a, b;
    while(N--) {
        cin >> c;
        if(c == 1) {
            cin >> a;
            ST.insert(a);
                
        } else {
            cin >> a >> b;
            ST.erase(ST.lower_bound(a), ST.upper_bound(b));
        }
        cout << min(int(ST.size()), 2);
        if(ST.size() > 0)
            cout << ' ' << *ST.begin();
        if(ST.size() > 1)
            cout << ' ' << *prev(ST.end());
        cout << '\n';
        //if(ST.begin()!=ST.end())
    }
    return 0;
}
