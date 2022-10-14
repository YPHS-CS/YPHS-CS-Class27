#include<iostream>
using namespace std;

int visited[50002];
int find(int x){
    if(visited[x] == x)
        return x;
    else
        return visited[x] = find(visited[x]);
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, s1, s2, people, Case=1;
    while(cin >> N >> M && N && M){
        people=N;
        for(int i=1;i<=N;i++){
            visited[i]=i;
        }
        while(M--){
            cin >> s1 >> s2;
            if(find(s1) == find(s2)) continue;

            visited[find(s1)] = find(s2);
            people--;
        }
        cout << "Case " << Case++ << ": " << people << '\n';
    }
    
    return 0;
}
