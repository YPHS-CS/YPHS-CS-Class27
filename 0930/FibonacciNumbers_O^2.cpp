//
//  FibonacciNumbers_O^2.cpp
//  動態規劃1
//
//  Created by 吳浩瑋 on 2022/8/21.
//
#include <iostream>
#include <assert.h>
using namespace std;


uint64_t fib(int x) {
    if(x <= 2) {
        return 1;
    }
    return fib(x-1) + fib(x-2);
}
int main() {
    int N;
    cin >> N;
    assert(N < );
    cout << fib(N) << '\n';
    return 0;
}
