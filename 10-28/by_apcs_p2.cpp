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

struct package
{
    int _wm,_h,_type;
    vi _w;
    package(char c)
    {
        _type=(int)(c-'A');
        switch(_type)
        {
            case 0:
                _wm=1;
                _h=4;
                _w={1,1,1,1};
                break;
            case 1:
                _wm=3;
                _h=1;
                _w.pb(3);
                break;
            case 2:
                _wm=2;
                _h=2;
                _w={2,2};
                break;
            case 3:
                _wm=3;
                _h=2;
                _w={1,3};
                break;
            default:
                _wm=2;
                _h=3;
                _w={1,2,2};
                break;
        }
    }
};

int n,r,c,sum=0,out=0;
vi barn;

signed main()
{
	settings();
    cin >> r >> c >> n;
    barn.assign(r,0);
    while(n--)
    {
        char p;
        int l,maxn=0;
        cin >> p >> l;
        package now(p);
        for(int i=0;i<now._h;++i)
            maxn = max(maxn,barn[l+i]+now._w[i]);
        if (maxn>c)
        {
            ++sum;
            continue;
        }
        for (int i=0;i<now._h;++i)
        {
            out += maxn - barn[l+i]-now._w[i];
            barn[l+i]=maxn;
        }
        debug_all(barn);
    }
    for(auto i:barn)
        out += c-i;
    cout << out << ' ' << sum << '\n';
	return 0;
}

