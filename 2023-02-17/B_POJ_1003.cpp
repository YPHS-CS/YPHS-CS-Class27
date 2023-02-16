#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    double X;
    vector<pair<double, int> > Nums;
    while(cin >> X and X)
        Nums.push_back(make_pair(X, Nums.size()));

    sort(Nums.begin(), Nums.end());
    double preSum = 0;
    int pointer = 0;
    vector<int> Ans(Nums.size());
    for(int i=1;pointer<Nums.size();++i) {
        preSum += 1.0/(i+1);
        while(pointer < Nums.size() and Nums[pointer].first < preSum) {
            Ans[Nums[pointer].second] = i;
            pointer ++;
        }
    }
    for(int i=0;i<Nums.size();++i) {
        cout << Ans[i] << " card(s)\n";
    }
    return 0;
}