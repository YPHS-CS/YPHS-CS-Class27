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

struct node
{
    int _v,_leaf;
    node(int x):_v(x)
    {
        if (x&1)
            _leaf=3;
        else
            _leaf=2;
    }
};

stack<node> tree;
int x,ans=0;
bool firstx=true;

signed main()
{
	settings();
    while(cin >> x)
    {
        if(x)
        {
            if (firstx)
            {
                firstx=false;
            }
            else
            {
                ans+=abs(tree.top()._v-x);
                --tree.top()._leaf;
            }
            tree.push(node(x));
        }
        else
        {
            --tree.top()._leaf;
        }
        while(!tree.empty()&&!tree.top()._leaf)
        {
            tree.pop();
        }
        if (tree.empty())
            break;
    }
    cout << ans << '\n';
	return 0;
}

