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

struct point
{
    int _x,_y;
    point(int x=0,int y=0):_x(x),_y(y){};
    point operator-(point b)
    {
        return point(this->_x-b._x,this->_y-b._y);
    }
    int norm()
    {
        return abs(this->_x)+abs(this->_y);
    }
};

const double eps = 1e-9;

int n,maxn=0,minn=INF;

v<point> points;

signed main()
{
	settings();
    cin >> n;
    for (int i=0;i<n;++i)
    {
        int x,y;
        cin >> x >> y;
        points.eb(x,y);
    }
    for (int i=1;i<n;++i)
    {
        point delta = points[i]-points[i-1];
        maxn=max(maxn,delta.norm());
        minn=min(minn,delta.norm());
    }
    cout << maxn << ' ' << minn << '\n';
	return 0;
}
