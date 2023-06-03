#include <iostream>
#include <vector>
#include <string>
using namespace std;


const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int N, M;
vector<string> Field;
void dfs(int x, int y) {
    Field[x][y] = '.';
    for(int i=0;i<8;++i) {
        int rx = x + dx[i], ry = y + dy[i];
        if(rx>=0 and ry>=0 and rx<N and ry<M and Field[rx][ry] == 'W') {
            dfs(rx, ry);
        }
    }
}
int main() {
    cin >> N >> M;
    Field.resize(N);
    for(int i=0;i<N;++i)
        cin >> Field[i];
    int ans = 0;
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) {
            if(Field[i][j] == 'W') {
                ++ans;
                dfs(i, j);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}