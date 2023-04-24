#include <iostream>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    uint64_t N;
    cin >> N;
    while(N != 1){
        cout << N << ' ';
        if(N%2)
            N = 3*N+1;
        else
            N /= 2;
    }
    cout << N << '\n';
    return 0;
}
