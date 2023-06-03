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

#define INF UINT64_MAX
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

struct node
{
	int _l,_r,_sum,_lt;
	node (int l=-1,int r=-1,int sum=0,int lazytag=0):_l(l),_r(r),_sum(sum),_lt(lazytag){}
};

struct human
{
	int _order,_value;
	human(int order=-1,int value=-1):_order(order),_value(value){}
	bool operator< (human b)
	{
		if (this->_value == b._value)
			return this->_order<b._order;
		return this->_value > b._value;
	}
};

v<node> seg_tree(400005);
v<human> people;
vi human_pos(100000);

int n;
int sum;
int nmax=0;

void pull(int pos)
{
	node &now = seg_tree[pos];
	if (now._l!=now._r)
		now._sum=seg_tree[pos<<1]._sum+seg_tree[(pos<<1)+1]._sum;
	now._sum+=now._lt;
}

void build (int pos,int l,int r)
{
	if (l==r)
	{
		seg_tree[pos]=node(l,r);
	}
	else
	{
		int m=l+(r-l)/2;
		build(pos << 1,l,m);
		build((pos<<1)+1,m+1,r);
		seg_tree[pos]._l=l;
		seg_tree[pos]._r=r;
		pull(pos);
	}
}

void modify(int pos,int l,int r,int v)
{
	node &now = seg_tree[pos];
	if (now._l>=l && now._r<=r)
	{
		now._lt+=v;
	}
	else
	{
		int m = now._l+(now._r-now._l)/2;
		if (l<=m)
			modify(pos<<1,l,r,v);
		if (r>m)
			modify((pos<<1)+1,l,r,v);
	}
	pull(pos);
}

void query(int pos,int l,int r,int add=0)
{
	node &now = seg_tree[pos];
	if (now._l>=l && now._r<=r)
	{
		sum+=now._sum+add*(r-l+1);
	}
	else
	{
		int m = now._l+(now._r-now._l)/2;
		if (l<=m)
			query(pos<<1,l,r,add+now._lt);
		if (r>m)
			query((pos<<1)+1,l,r,add+now._lt);
	}
}

signed main()
{
	settings();
	while(cin >> n)
	{
		nmax=0;
		for (int i=1;i<=n;++i)
		{
			int  m;
			cin >> m;
			people.push_back(human(i,m));
			nmax=max(nmax,m);
		}
		human_pos.resize(nmax+1);
		seg_tree.resize(4*nmax+1);
		sort(all(people));
		for (int i=0;i<n;++i)
			human_pos[people[i]._order]=i;
		build(1,1,nmax);
		for (int i=1;i<=n;++i)
		{
			int now_pos=human_pos[i];
			modify(1,1,people[now_pos]._value,1);
			sum=0;
			query(1,people[now_pos]._value,people[now_pos]._value);
			cout << sum << '\n';
		}
		seg_tree.clear();
		human_pos.clear();
		people.clear();
	}
	return 0;
}
