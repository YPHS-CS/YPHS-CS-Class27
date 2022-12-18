#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()
struct QUERY
{
    int L, R, id;
    QUERY() {}
    QUERY(int l_, int r_, int id_) : L(l_), R(r_), id(id_) {}
};
int block;
bool operator<(const QUERY &a, const QUERY &b)
{
    if ((a.L / block) == (b.L / block))
    {
        return (a.L / block) & 1 ? a.R < b.R : a.R > b.R;
    }
    else
    {
        return a.L < b.L;
    }
}
int N, M;
int cur_ans;
vector<int> Nums;
vector<int> cnt;
unordered_map<int, int> Ref;
vector<QUERY> query;
void sub(int x)
{
    if (Ref[x] == cur_ans and cnt[Ref[x]] == 1)
        cur_ans = Ref[x] - 1;
    cnt[Ref[x]]--;
    cnt[--Ref[x]]++;
}
void add(int x)
{
    if (Ref[x] == cur_ans and cnt[Ref[x] + 1] == 0)
        cur_ans = Ref[x] + 1;
    cnt[Ref[x]]--;
    cnt[++Ref[x]]++;
}
int L = 0, R = -1;
void solve()
{
    vector<pair<int, int>> ans(M);
    for (auto q : query)
    {
        while (R < q.R)
            add(Nums[++R]);
        while (L > q.L)
            add(Nums[--L]);
        while (R > q.R)
            sub(Nums[R--]);
        while (L < q.L)
            sub(Nums[L++]);
        ans[q.id] = mp(cur_ans, cnt[cur_ans]);
    }
    for (auto i : ans)
    {
        cout << i.first << ' ' << i.second << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    block = sqrt(N);
    Nums.resize(N);
    cnt.resize(N + 1);
    query.resize(M);
    for (int &i : Nums)
        cin >> i;
    for (int i = 0, l, r; i < M; ++i)
    {
        cin >> l >> r;
        query[i] = QUERY(l - 1, r - 1, i);
    }
    sort(all(query));
    solve();
    return 0;
}
