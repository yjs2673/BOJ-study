// 재귀
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

int n;
int map[64][64];

void init() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            map[i][j] = s[j] - '0';
        }
    }
}

bool check(int x, int y, int size) {
    int flag = map[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (flag != map[i][j]) return false;
        }
    }
    return true;
}

void zip(int x, int y, int size) {
    if (size == 1) {
        cout << map[x][y];
        return;
    }
    
    if (check(x, y, size)) cout << map[x][y];
    else {
        cout << '(';
        zip(x, y, size/2);
        zip(x, y + size/2, size/2);
        zip(x + size/2, y, size/2);
        zip(x + size/2, y + size/2, size/2);
        cout << ')';
    }
}

int main() {
    init();
    zip(0, 0, n);
    return 0;
}
