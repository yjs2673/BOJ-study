// 다익스트라 n번
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <numeric>

using namespace std;

int n, m, x, max_dis = 0;
int inf = 999999;
int all_dis[1001][1001];
vector<pair<int, int>> graph[1001];

void init() {
    cin >> n >> m >> x;
    
    for (int i = 0; i < m; i++) {
        int u, v, time;
        cin >> u >> v >> time;
        graph[u].push_back({v, time});
    }
}

void dijkstra(int start) {
    vector<int> dis(1001, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, start});
    dis[start] = 0;
        
    while (!Q.empty()) {
        int sum_dis = Q.top().first;
        int x = Q.top().second;
        Q.pop();
        
        if (dis[x] < sum_dis) continue;
        
        for (int i = 0; i < graph[x].size(); i++) {
            int new_x = graph[x][i].first;
            int new_cost = sum_dis + graph[x][i].second;
            
            if (dis[new_x] > new_cost) {
                Q.push({new_cost, new_x});
                dis[new_x] = new_cost;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        all_dis[start][i] = dis[i];
    }
    return;
}

void compare() {
    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        
        int new_dis = all_dis[i][x] + all_dis[x][i];
        if (new_dis > max_dis) max_dis = new_dis;
    }
    
    cout << max_dis << endl;
    return;
}

int main() {
    init();
    for(int i = 1; i <= n; i++) dijkstra(i);
    compare();
    return 0;
}
