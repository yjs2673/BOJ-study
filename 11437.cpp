// LCA
// 레벨 관리에서는 union-find보다 dfs가 효율적이다.
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <numeric>
#include <cmath>
#include <cstdio>

using namespace std;

int n, m;
vector<int> tree[50001];
int parent[50001];
int level[50001];

void dfs(int node, int par, int lv) {
    parent[node] = par;
    level[node] = lv;
    for (int i = 0; i < tree[node].size(); i++) {
        int new_node = tree[node][i];
        if (new_node != par) dfs(new_node, node, lv + 1);
        // 부모랑 연결된 케이스는 제외
    }
}

void init() {
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    dfs(1, 0, 1);
    // 루트의 노드, 부모, 레벨은 각각 1, 0, 1
}

int LCA(int a, int b) { // 과정 간단하게 줄이기
    while(level[a] > level[b]) a = parent[a];
    while(level[b] > level[a]) b = parent[b];
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

void quest() {
    cin >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << endl;
    }
}

int main() {
    init();
    quest();
    return 0;
}
