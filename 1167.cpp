// DFS
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

int v, max_node, max_dis = 0;
bool visited[100001] = {false,};
vector<pair<int, int>> tree[100001];

void init() {
    cin >> v;
    for (int i = 1; i <= v; i++) {
        int parent;
        cin >> parent;
        
        while (true) {
            int child, cost;
            cin >> child;
            if (child == -1) break;
            cin >> cost;
            tree[parent].push_back({child, cost});
            tree[child].push_back({parent, cost});
        }
    }
}

void dfs(int x, int distance) {
    if (visited[x]) return;
    
    visited[x] = true;
    if (distance > max_dis) {
        max_dis = distance;
        max_node = x;
    }
    for (int i = 0; i < tree[x].size(); i++) {
        dfs(tree[x][i].first, distance + tree[x][i].second);
    }
}

int main() {
    init();
    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    max_dis = 0;
    dfs(max_node, 0);
    cout << max_dis << endl;
    return 0;
}
