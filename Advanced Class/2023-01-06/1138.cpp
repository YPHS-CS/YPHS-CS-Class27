#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N;
vector<vector<double>> MP;
vector<double> operator*(vector<double> v, double x)
{
    for (double &i : v)
        i *= x;
    return v;
}
vector<double> operator-(vector<double> a, vector<double> b)
{
    for (int i = 0; i < a.size(); ++i)
    {
        a[i] -= b[i];
    }
    return a;
}
bool cmp(vector<double> a, vector<double> b)
{
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
    return 0;
}
int input_integer()
{
    int x;
    cin >> x;
    return x;
}
void solve()
{
    sort(MP.begin(), MP.end(), cmp);
    for (int i = 0; i < N; ++i)
    {
        int pri = i;
        while (pri < N and MP[pri][i] == 0)
            ++pri;
        if (pri == N)
            continue;
        swap(MP[pri], MP[i]);
        for (int j = i + 1; j < N; ++j)
        {
            MP[j] = MP[j] - MP[i] * (MP[j][i] / MP[i][i]);
        }
    }
    for (int i = N - 1; i >= 0; --i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            MP[j] = MP[j] - MP[i] * (MP[j][i] / MP[i][i]);
        }
        MP[i] = MP[i] * (1.0 / MP[i][i]);
    }
    for (auto i : MP)
    {
        cout << round(i[N]) << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int K = input_integer();
    while (K--)
    {
        N = input_integer();
        MP.assign(N, vector<double>(N + 1));
        for (int i = 0, m; i < N; ++i)
        {
            m = input_integer();
            for (int j = 0; j < m; ++j)
            {
                MP[i][input_integer()] = 1;
            }
            MP[i][N] = input_integer();
        }
        solve();
    }
    return 0;
}