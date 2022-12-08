#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define int long long
#define ld long double

#ifdef ONLINE_JUDGE
	#define settings() ios::sync_with_stdio(0);cin.tie(0)
#elif defined(sublime)
	#include <cstdio>
	#define settings() freopen("pG.in","r",stdin) // Because Sublime Text doesn't support input from terminal.
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
#define vii v< vi >

#define lowbit(x) (x)&(-x)

#define setpoint(x) fixed << setprecision(x)

const double eps = 1e-9;

int n,m;

vii graph,graph2;
vi d1,d2;
vi father;
int ans=0;

// 併查集
int find(int x)
{
	if (father[x]==x)
		return x;
	return father[x]=find(father[x]);
}

// 從x出發的最遠點
int dp1(int x)
{
	if (d1[x])
		return d1[x];
	int ret=0;
	for (auto i:graph[x])
	{
		ret = max(dp1(i)+1,ret);
	}
	return d1[x]=ret;
}

// 以x為終點時之最遠點
int dp2(int x)
{
	if (d2[x])
		return d2[x];
	int ret=0;
	for (auto i:graph2[x])
	{
		ret = max(dp2(i)+1,ret);
	}
	return d2[x]=ret;
}

signed main()
{
	settings();
	cin >> n >> m;
	graph.resize(n+1);
	graph2.resize(n+1);
	d1.resize(n+1);
	d2.resize(n+1);
	father.resize(n+1);
	for (int i=0;i<=n;++i)
		father[i]=i;
	for (int i=0;i<m;++i)
	{
		int x,y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph2[y].push_back(x);
		father[find(y)]=find(x);
	}
	vi num(n+1);
	for(int i=1;i<=n;++i)
	{
		dp1(i);
		dp2(i);
	}
	for (int i=1;i<=n;++i)
	{
		ans=max(d1[i]+d2[i],ans);
	}
	cout << ans << '\n';
	return 0;
}
