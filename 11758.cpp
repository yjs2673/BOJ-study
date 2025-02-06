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

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    int result = (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3- x1);
    if (result > 0) cout << 1 << endl;
    else if (result < 0) cout << -1 << endl;
    else cout << 0 << endl;
    return 0;
}
