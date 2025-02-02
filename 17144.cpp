// BFS
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

int r, c, t, total = 0;
int Ar1 = 0, Ar2 = 0;
int map[50][50];
int plus_map[50][50] = {0,};

void init() {
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int num;
            cin >> num;
            map[i][j] = num;
            if (num == -1) {
                if (Ar1 == 0) Ar1 = i;
                else Ar2 = i;
            }
            else if (num != 0) total += num;
        }
    }
}

void spread(int x, int y) {
    int cnt = 0, dust = map[x][y];
    if (x >= 1 && map[x - 1][y] != -1) {
        plus_map[x - 1][y] += dust / 5;
        cnt++;
    }
    if (x <= r - 2 && map[x + 1][y] != -1) {
        plus_map[x + 1][y] += dust / 5;
        cnt++;
    }
    if (y >= 1 && map[x][y - 1] != -1) {
        plus_map[x][y - 1] += dust / 5;
        cnt++;
    }
    if (y <= c - 2) {
        plus_map[x][y + 1] += dust / 5;
        cnt++;
    }
    
    map[x][y] -= cnt * (dust / 5);
}

void dust_move() {
    map[Ar1 - 1][0] = 0;
    map[Ar2 + 1][0] = 0;
    // 청정기 아래쪽 사이클
    for (int i = Ar2 + 1; i < r - 1; i++) map[i][0] = map[i + 1][0];
    for (int i = 0; i < c - 1; i++) map[r - 1][i] = map[r - 1][i + 1];
    for (int i = r - 1; i > Ar2; i--) map[i][c - 1] = map[i - 1][c - 1];
    for (int i = c - 1; i > 1; i--) map[Ar2][i] = map[Ar2][i - 1];
    map[Ar2][1] = 0;
    // 청정기 위쪽 사이클
    for (int i = Ar1 + 1; i > 0; i--) map[i][0] = map[i - 1][0];
    for (int i = 0; i < c - 1; i++) map[0][i] = map[0][i + 1];
    for (int i = 0; i < Ar1; i++) map[i][c - 1] = map[i + 1][c - 1];
    for (int i = c - 1; i > 1; i--) map[Ar1][i] = map[Ar1][i - 1];
    map[Ar1][1] = 0;
}

void cycle() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] > 0) spread(i, j);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            map[i][j] += plus_map[i][j];
        }
    }
    dust_move();
    total = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] > 0) total += map[i][j];
        }
    }
    memset(plus_map, 0, sizeof(plus_map));
}

int main() {
    init();
    for (int i = 0; i < t; i++) cycle();
    cout << total << endl;
    return 0;
}
// 예제 결과는 다 맞는데 반례가 몇 개 있음. 어떻게 고쳐야 할 지를 모르겠다
