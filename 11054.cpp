// 다이나믹 프로그래밍
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int n, max_len = 0;
vector<int> arr;

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a > b ? b : a;
}

void bitonic() {
    vector<int> LSI(n, 1);
    vector<int> LDI(n, 1);
        
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {        // 증가 부분
            if(arr[i] > arr[j]) LSI[i] = max(LSI[j] + 1, LSI[i]);
        }
    }
    
    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j > i; j--) {    // 감소 부분
            if(arr[i] > arr[j]) LDI[i] = max(LDI[j] + 1, LDI[i]);
        }
    }
    // LSI, LDI는 해당 인덱스의 arr 값을 중심으로 양방향으로 진행된다. 따라서 LSI[i] + LDI[i] 해주면 됨
    for(int i = 0; i < n; i++) max_len = max(max_len, LSI[i] + LDI[i] - 1);
    return;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    
    bitonic();
    
    cout << max_len << endl;
    return 0;
}
