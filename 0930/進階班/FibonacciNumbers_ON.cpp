//
//  FibonacciNumbers_ON.cpp
//  動態規劃1
//
//  Created by 吳浩瑋 on 2022/8/21.
//
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;


int main() {
    int N;
    cin >> N;
    assert(0 <= N and N <= 93);
    vector<uint64_t> vec(N+1);
    vec[1] = vec[2] = 1;
    for(int i=3;i<=N;++i) {
        vec[i] = vec[i-1] + vec[i-2];
    }
    cout << vec[N] << '\n';
    return 0;
}
