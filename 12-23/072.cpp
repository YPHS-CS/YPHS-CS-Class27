#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int T,N;
double ans,p[5];
double a[15],b[15],c[15];
double maxc,v2,v3;
double f(double t){
    double res=-1;
    for(int i=0;i<N;++i)
        res=max(res,a[i]*(t-b[i])*(t-b[i])+c[i]);
    return res;
}
int main(){
    cin >> T;
    while(T--){
        maxc=-1;
        cin >> N;
        for(int i=0;i<N;++i){
            cin >> a[i] >> b[i] >> c[i];
            if(a[i]==0){
                maxc=max(maxc,c[i]);
                --i,--N;
            }
        }
        p[1]=0,p[4]=300;
        for(int i=0;i<100;++i){
            p[2]=p[1]+(p[4]-p[1])/3;
            p[3]=p[1]+(p[4]-p[1])/3*2;
            v2=f(p[2]),v3=f(p[3]);
            if(v2<v3)
                p[4]=p[3];
            else
                p[1]=p[2];
        }
        ans=max(f(p[1]),maxc);
        cout << fixed << setprecision(6) << ans << '\n';
    }
    return 0;
}