#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


struct E {
    int item_max = -1;
    int item_sum = 0;
};
const int MAX_N = 1e5;
vector<int> children [MAX_N + 2];
E child_amount [MAX_N + 2];
int get_max(int it) {
    if (child_amount [it].item_max >= 0)
        return child_amount [it].item_max;
    else {
        int MAX = 0;
        for (int i = 0;i < children [it].size();i++) {
            MAX = max(get_max(children [it][i]), MAX);
        }
        return child_amount [it].item_max = MAX + 1;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    while (cin >> N) {
        for (int i = 0;i < N;i++){
            children [i].clear();
            child_amount[i].item_max = -1;
            child_amount[i].item_sum = 0;
        }
        for (int i = 0;i < N - 1;i++) {
            int a, b;
            cin >> a >> b;
            children [a].push_back(b);
        }
        for (int i = 0;i < N;i++) {
            if (children [i].size() == 0)
                child_amount [i].item_max = 0;
        }
        int MAX = 0;
        for (int i = 0;i < N;i++) {
            int m=0;
            vector<int>vec(children[i].size());
            for (auto j : children [i]) {
                vec.push_back(get_max(j)+1);
            }
            sort(vec.begin(), vec.end());
            if (vec.size() == 1)
                m = max(vec[0], m);
            else if (vec.size() >= 2)
                m = max(vec [vec.size() - 1] + vec [vec.size() - 2]+1, m);
            MAX = max(m-1, MAX);
        }
        cout<<MAX<<endl;
    }
    return 0;
}
