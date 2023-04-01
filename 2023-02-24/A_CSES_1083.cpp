#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> Nums(N - 1);
    for (int& i : Nums) cin >> i;
    sort(Nums.begin(), Nums.end());
    for (int i = 0;i < N;++i) {
        if (Nums [i] != i + 1) {
            cout << i + 1 << '\n';
            break;
        }
    }
    return 0;
}