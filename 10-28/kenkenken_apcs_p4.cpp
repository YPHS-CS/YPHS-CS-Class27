#include <bits/stdc++.h>
using namespace std;

int n, tt;
int a[305][305], vis[305][305], mn[305][305];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int m) {
    tt++;
    queue<pair<int, int>> q;
    q.push({1, 1});
    vis[1][1] = tt;
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (a[nx][ny] < 0) continue;
            if (abs(a[nx][ny] - a[x][y]) > m) continue;
            if (vis[nx][ny] < tt) {
                vis[nx][ny] = tt;
                mn[nx][ny] = mn[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    memset(a, -1, sizeof(a));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    int l = 0, r = 1e6;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        bfs(m);
        if (vis[n][n] == tt) r = m;
        else l = m;
    }
    bfs(r);
    cout << r << '\n' << mn[n][n] << '\n';
}
