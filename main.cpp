// Union-Find
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n, m, turn = 0;
vector<int> parent;

int find(int);
void union_set(int, int);

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) parent.push_back(i);
    while(m--) {
        int u, v;
        cin >> u >> v;
        turn++;
        
        if(find(u) == find(v)) {
            cout << turn << endl;
            return 0;
        }
        
        union_set(u, v);
    }
    
    cout << "0" << endl;
    return 0;
}

int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void union_set(int u, int v) {
    int up = find(u), vp = find(v);
    
    if(up != vp) {
        if(up < vp) parent[vp] = up;    // parent[v] = up는 오답
        else parent[up] = vp;           // parent[u] = vp는 오답
    }
    return;
}
