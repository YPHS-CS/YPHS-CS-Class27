//
//  Zerojudge_E417.cpp
//  複雜度
//
//  Created by 吳浩瑋 on 2022/8/21.
//
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

#define all(x) (x).begin(), (x).end()


int main(){
    int N;
    vector<int> nums;
    while(cin >> N) {
        nums.resize(N);
        for(int &i:nums) cin >> i;
        uint64_t s1, s2;
        s1 = s2 = 0;
        for(int i:nums) {
            s1 += i;
            s2 += i*i;
        }
        cout << (uint64_t)(s1*s1 - s2) / 2 << '\n';
    }
    return 0;
}
