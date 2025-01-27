// dijkstra
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, e, A, B;
int INF = 98765432;
vector<pair<int, int>> graph[801];
int dis[801];

void dijkstra(int start) {
    memset(dis, INF, sizeof(dis));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push(make_pair(0, start));
    dis[start] = 0;
    
    while(!Q.empty()) {
        int sum_dis = Q.top().first;
        int x = Q.top().second;
        Q.pop();
        
        if(dis[x] < sum_dis) continue;
        
        for(int i = 0; i < graph[x].size(); i++) {
            int new_x = graph[x][i].first;
            int new_cost = sum_dis + graph[x][i].second;
            
            if(dis[new_x] > new_cost) {
                Q.push({new_cost, new_x});
                dis[new_x] = new_cost;
            }
        }
    }
}

int min(int a, int b) {
    return a > b ? b : a;
}

int main() {
    cin >> n >> e;
    for(int i = 0; i < e; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].push_back({v, cost});
        graph[v].push_back({u, cost});
    }
    cin >> A >> B;
    
    dijkstra(1);
    int to_A = dis[A];
    int to_B = dis[B];
    
    dijkstra(A);
    int A_to_B = dis[B];
    int A_to_n = dis[n];
    
    dijkstra(B);
    int B_to_n = dis[n];
    
    int result = min(INF, to_A + A_to_B + B_to_n);
    result = min(result, to_B + A_to_B + A_to_n);
    
    if(result >= INF) cout << -1 << endl;
    else cout << result << endl;
    return 0;
}
