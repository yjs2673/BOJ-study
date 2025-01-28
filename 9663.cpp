// 백트래킹
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int n, cnt = 0;                  // n = 4 일 때,
bool visit_down[15] = {false,};  // 0 1 2 3
bool visit_right[29] = {false,}; // -3 -2 -1 0 1 2 3 (n-1 씩 더해서 보정)
bool visit_left[29] = {false,};  // 0 1 2 3 4 5 6

void Queen(int depth) {
    if(depth == n) {
        cnt++;
        return;
    }
    
    for(int i = 0; i < n; i++) {
        if(!visit_down[i] && !visit_right[depth - i + n - 1] && !visit_left[depth + i]) {
            visit_down[i] = true;
            visit_right[depth - i + n - 1] = true;
            visit_left[depth + i] = true;
            
            Queen(depth + 1);
            
            visit_down[i] = false;
            visit_right[depth - i + n - 1] = false;
            visit_left[depth + i] = false;
        }
    }
}

int main() {
    cin >> n;
    
    Queen(0);
    
    cout << cnt << endl;
    return 0;
}
