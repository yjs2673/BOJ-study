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
#include <tuple>

using namespace std;

typedef pair<long, long> pii;

int ccw(pii a, pii b, pii c) {
    long long res = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
    if (res > 0) return 1;   // 반시계 방향
    if (res < 0) return -1;  // 시계 방향
    return 0;                // 일직선
}

bool cross(pair<pii, pii> l1, pair<pii, pii> l2) {
    pii p1 = l1.first, p2 = l1.second;
    pii p3 = l2.first, p4 = l2.second;

    int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    // 일직선상에 존재하는 경우, 겹치는지 확인
    if (p1p2 == 0 && p3p4 == 0) {
        if (p1 > p2) swap(p1, p2);
        if (p3 > p4) swap(p3, p4);
        return p3 <= p2 && p1 <= p4;
    }

    return p1p2 <= 0 && p3p4 <= 0;
}

int main() {
    pii p1, p2, p3, p4;
    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    cin >> p3.first >> p3.second >> p4.first >> p4.second;

    cout << cross({p1, p2}, {p3, p4}) << "\n";
    return 0;
}
