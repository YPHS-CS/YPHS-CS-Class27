//
//  Zerojudge_A007.cpp
//  複雜度
//
//  Created by 吳浩瑋 on 2022/8/21.
//
#include <iostream>
#include <vector>
using namespace std;


vector<bool> table(46345, true);
vector<int> primeNumber;
inline void init() {
    for(int i=2;i<46345;++i) {
        if(table[i]) {
            primeNumber.push_back(i);
            for(int j=i;i*j<46345;++j) {
                table[i*j] = false;
            }
        }
    }
}
inline bool isPrimeNumber(int x) {
    if(x < 46345) {
        return table[x];
    } else {
        for(int i:primeNumber) {
            if(x % i == 0)
                return false;
        }
        return true;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int x;
    while(cin >> x){
        if(isPrimeNumber(x)) {
            cout << "質數" << '\n';
        } else {
            cout << "非質數" << '\n';
        }
    }
    return 0;
}
