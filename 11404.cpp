// floyd-warshall
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

#define inf 9876543
int v, e;
int graph[401][401];

void init() {
    memset(graph, inf, sizeof(graph));
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u][v] = cost;
    }
}

void floyd() {
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                int new_dis = graph[i][k] + graph[k][j];
                if (new_dis < graph[i][j]) graph[i][j] = new_dis;
            }
        }
    }
}

void cycle() {
    int min = inf;
    for (int i = 1; i <= v; i++) if (graph[i][i] < min) min = graph[i][i];
    if (min < inf) cout << min << endl;
    else cout << -1 << endl;
}

int main() {
    init();
    floyd();
    cycle();
    return 0;
}
