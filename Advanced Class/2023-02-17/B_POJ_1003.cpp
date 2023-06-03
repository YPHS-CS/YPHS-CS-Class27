#include <iostream>
using namespace std;


int main() {
    double X;
    while(cin >> X and X) {
        double preSum = 0;
        for(int i=1;preSum < X;++i) {
            preSum += 1.0/(i+1);
            if(X <= preSum)
                cout << i << " card(s)\n";
        }
    }
    return 0;
}
