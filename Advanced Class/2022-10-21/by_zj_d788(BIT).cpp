#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

#define int long long
#define ld long double

#ifdef ONLINE_JUDGE
	#define settings() ios::sync_with_stdio(0);cin.tie(0)
#elif defined(sublime)
	#include <cstdio>
	#define settings() freopen("d788.in","r",stdin) // Because Sublime Text doesn't support input from terminal.
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

#define v vector
#define vi v< int >
#define vii v< vi >

#define lowbit(x) (x)&(-x)

#define setpoint(x) fixed << setprecision(x)

const double eps = 1e-9;

vi bit,people;

int n,maxg=0;

void modify(int x,int value)
{
	while (x<=maxg)
	{
		bit[x]+=value;
		x+=lowbit(x);
	}
}

int sum(int x)
{
	int ret=0;
	while (x>0)
	{
		ret+=bit[x];
		x-=lowbit(x);
	}
	return ret;
}

signed main()
{
	settings();
	while(cin >> n)
	{
		people.resize(n);
		for (auto &i:people)
		{
			cin >> i;
			maxg=max(maxg,i);
		}
		bit.resize(maxg+1);
		for (auto i:people)
		{
			modify(1,1);
			modify(i+1,-1);
			cout << sum(i) << '\n';
		}
		people.clear();
		bit.clear();
	}
	return 0;
}
