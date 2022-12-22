#include<iostream>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

int N;
int arr[(int)(1e6+2)];
set<int>all;
void read(){
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>arr[i];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	read();
    for(int i=0;i<N;i++)
        all.insert(arr[i]);
    int s=0, e=0, MIN=N, amount=0;
    map<int, int>taken;
    for(;s<N;s++){
        while(amount<all.size()){
            if(e>=N)
                goto END;
            if(taken[arr[e++]]++ ==0)
                amount++;
        }
        MIN = min(e-s, MIN);
        if(--taken[arr[s]]==0)
            amount--;
    }
END:
    cout<<MIN<<endl;
	return 0;
}
/*
P -> [1, 1000000]
*/
// finish time: 915	sec
