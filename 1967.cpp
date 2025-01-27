// DFS
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, max_dis = 0, max_node = 0;
bool visited[10001] = {false,};
vector<pair<int, int>> tree[10001];

void dfs(int x, int distance) {
    if(visited[x]) return;
    
    visited[x] = true;
    
    if(distance > max_dis) {
        max_dis = distance;
        max_node = x;
    }
    
    for(int i = 0; i < tree[x].size(); i++) {
        dfs(tree[x][i].first, tree[x][i].second + distance);
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        tree[u].push_back({v, cost});
        tree[v].push_back({u, cost});
    }
    
    dfs(1, 0);
    
    max_dis = 0;
    memset(visited, false, sizeof(visited));
    dfs(max_node, 0);
    
    cout << max_dis << endl;
    return 0;
}
