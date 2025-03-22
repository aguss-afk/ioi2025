#include <bits/stdc++.h>
using namespace std;
struct union_find {
    vector<int> arr;
    union_find(int n){
        arr.assign(n, 0);
        iota(arr.begin(), arr.end(), 0);
    }
    int find(int a){
        return arr[a] = (arr[a] == a ? a : find(arr[a]));
    }
    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        arr[b] = a;
    }
};
int main(){
    int n, m; 
    cin >> n >> m;
    union_find arr(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        arr.unite(a, b);
    }
    unordered_set<int> diff;
    for(int i = 0; i < n; i++) diff.insert(arr.find(arr.arr[i]));
    cout << diff.size() - 1;
}