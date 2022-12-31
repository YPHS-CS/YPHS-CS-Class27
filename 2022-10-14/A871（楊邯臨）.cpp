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
    #define settings() freopen("a871.in","r",stdin) // Because Sublime Text doesn't support input from terminal.
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

#define v vector
#define vi v< int >
#define vii v< vi >

#define lowbit(x) (x)&(-x)

#define setpoint(x) fixed << setprecision(x)

const double eps = 1e-9;

struct vec
{
    double _x,_y;
    vec(double x,double y):_x(x),_y(y)
    {}
    vec operator- (vec b)
    {
        return vec(this->_x-b._x,this->_y-b._y);
    }
    bool operator== (vec b)
    {
        return (this->_x==b._x)&&(this->_y==b._y);
    }
};

double vec_cross(vec a, vec b)
{
    return a._x*b._y-a._y*b._x;
}

int n;
double ans;

signed main()
{
    settings();
    while (cin >> n)
    {
        ans=0;
        v<vec> upper_convex,lower_convex,nodes,graph;
        for (int i=0;i<n;++i)
        {
            double x,y;
            cin >> x >> y;
            nodes.push_back(vec(x,y));
        }
        sort(all(nodes),
            [](vec a, vec b)
            {if (a._x==b._x)
                return a._y<=b._y;
            return a._x<=b._x;
        });
        int now;
        for (int i=0;i<n;++i)
        {
            if (i==0||i==1)
            {
                lower_convex.push_back(nodes[i]);
                continue;
            }
            now=lower_convex.size()-1;
            while (lower_convex.size()>1&&vec_cross(nodes[i]-lower_convex[now-1],lower_convex[now]-lower_convex[now-1])>0)
            {
                lower_convex.pop_back();
                --now;
            }
            lower_convex.push_back(nodes[i]);
        }
        for (int i=0;i<n;++i)
        {
            if (i==0||i==1)
            {
                upper_convex.push_back(nodes[i]);
                continue;
            }
            now=upper_convex.size()-1;
            while (upper_convex.size()>1&&vec_cross(nodes[i]-upper_convex[now-1],upper_convex[now]-upper_convex[now-1])<0)
            {
                upper_convex.pop_back();
                --now;
            }
            upper_convex.push_back(nodes[i]);
        }
        reverse(all(upper_convex));
        upper_convex.pop_back();
        lower_convex.pop_back();
        for (int i=1;i<lower_convex.size();++i)
        {
            ans+=vec_cross(lower_convex[i-1],lower_convex[i]);
            debug(ans);
        }
        for (int i=1;i<upper_convex.size();++i)
        {
            ans+=vec_cross(upper_convex[i-1],upper_convex[i]);
            debug(ans);
        }
        ans+=vec_cross(lower_convex.back(),upper_convex.front());
        ans+=vec_cross(upper_convex.back(),lower_convex.front());
        cout << setpoint(2) << abs(ans)/2 << '\n';
    }
    return 0;
}
