#include<stdio.h>
#include<algorithm>
using namespace std;


pair<int, int> arr[10002];
int N;


bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}
int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        scanf("%d %d", &arr[i].first, &arr[i].second);
    
    sort(arr, arr+N, cmp);
	int sum=0, f=-1, e=-1;
    for(int i=0;i<N;i++){
		if(arr[i].first<=e){
			if(arr[i].second>e){
				sum+=arr[i].second-e;
				e=arr[i].second;
			} 
		}
		else{
			f=arr[i].first;
			e=arr[i].second;
			sum+=e-f;
		}
	}
	printf("%d\n", sum);
    return 0;
}
