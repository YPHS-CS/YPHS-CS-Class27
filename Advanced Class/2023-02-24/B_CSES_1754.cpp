#include <iostream>
using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        if (A > B)
            swap(A, B);
        int t = (2 * A - B);
        if (t >= 0 and t % 3 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}