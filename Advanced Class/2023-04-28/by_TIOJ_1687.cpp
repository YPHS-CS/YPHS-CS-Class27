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

#define settings() ios::sync_with_stdio(0);cin.tie(0)

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

int n,q,ans=0;
vvi G,P;
vi link,lev;

void dfs(int x,int level)
{
	if (~lev[x])
		return;
	link[level]=x;
	lev[x]=level;
	for (int i=0;(1<<i)<=level;++i)
		P[x][i]=link[level-(1<<i)];
	for (auto i:G[x])
		dfs(i,level+1);
	link[level]=-1;
}

int find_ancestor(int x,int count)
{
	if(count <= 0)
	{
		return x;
	}
	else
	{
		int c = 0;
		while ((1<<(c+1))<=count)
			++c;
		return find_ancestor(P[x][c],count-(1<<c));
	}
}

int lca(int a,int b)
{
	if (lev[a]<lev[b])
		swap(a,b);
	int a1 = find_ancestor(a,lev[a]-lev[b]);
	if (a1 == b)
		return a1;
	for (int i=P[a1].size()-1;i>=0;--i)
	{
		if (P[a1][i]!=P[b][i])
		{
			a1 = P[a1][i];
			b = P[b][i];
		}
	}
	return P[a1][0];
}

signed main()
{
	settings();
    cin >> n >> q;
	G.assign(n,vi());
	P.assign(n,vi(__lg(n)+1));
	link.assign(n,-1);
	lev.assign(n,-1);
	for (int i=0;i<n-1;++i)
    {
        int a,b;
        cin >> a >> b;
		G[a-1].pb(b-1);
		G[b-1].pb(a-1);
	}
	dfs(0,0);
	for (int i=0;i<q;++i)
	{
		int s,t,k;
		cin >> s >> t >> k;
		s -= 1;
		t -= 1;
		int L = lca(s,t);
		if (k<lev[s]-lev[L])
			ans = find_ancestor(s,k);
		else if (lev[s]+lev[t]-2*lev[L]>=k)
			ans = find_ancestor(t,lev[s]+lev[t]-2*lev[L]-k);
		else
			ans = -2;
		cout << ans+1 << '\n';
	}
	return 0;
}