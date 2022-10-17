#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	string S;
	cin >> S;
	string T(S);
	copy(S.rbegin(), S.rend(), T.begin());
	cout << (S==T ? "yes" : "no") << '\n';
	return 0;
}
