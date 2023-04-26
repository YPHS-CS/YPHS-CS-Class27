// 解題思路：Floyd Cycle Detection Algorithm
#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define int long long
#define ld long double

#ifdef ONLINE_JUDGE
	#define settings() ios::sync_with_stdio(0);cin.tie(0)
#elif defined(sublime)
	#include <cstdio>
	#define settings() freopen("file.in","r",stdin) // Because Sublime Text doesn't support input from terminal.
#else
	#define settings()
#endif

#define INF INT64_MAX/100
#define all(x) x.begin(),x.end()

#ifdef ONLINE_JUDGE
    #define debug(x)
#else
    #define debug(x) cerr << #x << " = " << x << '\n'
#endif

#ifdef ONLINE_JUDGE
	#define debug_all(x)
#else
	#define debug_all(x) {cerr << #x << ": "; for (auto i:x) cerr << i << ' '; cerr << '\n';}
#endif

#ifdef ONLINE_JUDGE
	#define debug_enter()
#else
	#define debug_enter() cerr << "\n";
#endif

#define v vector
#define vi v< int >
#define vvi v< vi >

#define lowbit(x) (x)&(-x)

#define pb push_back
#define eb emplace_back

#define setpoint(x) fixed << setprecision(x)

const double eps = 1e-9;

int square(int x,int n)
{
    // 依題目敘述之平方函數
    int ret = x*x;
    stack<int> st;
    while (ret>0)
    {
        st.push(ret%10);
        ret/=10;
    }
    int i=0;
    ret = 0;
    while (!st.empty())
    {
        if (i<n)
        {
            ret *= 10;
            ret += st.top();
        }
        ++i;
        st.pop();
    }
    return ret;
}

int t,n,k,maxn;

signed main()
{
	settings();
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int k1,k2;
        k1 = k2 = k;
        maxn = k;
        do
        {
            k1 = square(k1,n);
            maxn = max(maxn,k1);
            k2 = square(k2,n);
            maxn = max(maxn,k2);
            k2 = square(k2,n);
            maxn = max(maxn,k2);
        } while (k1 != k2);
       cout << maxn << '\n'; 
    }
	return 0;
}