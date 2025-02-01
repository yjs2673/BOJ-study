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

void exper(int num) {                       // long long으로도 표현할 수 없다 -> 문자열로 출력하기
    string exp = to_string(pow(2, num));
    int x = exp.find('.');                  // pow()는 자료형이 float이므로, 소수점 이하는 빼기
    exp = exp.substr(0, x);                 // 소수점 앞까지 사용
    exp[exp.length() - 1] -= 1;
    
    cout << exp << endl;
    return;
}

void hanoi(int start, int mid, int end, int depth) {
    if (depth == 1) printf("%d %d\n", start, end);
    else {                                  // printf가 cout보다 빠르다!
        hanoi(start, end, mid, depth - 1);  // printf : 버퍼링이 적고 단순함
        printf("%d %d\n", start, end);      // cout : 싱크와 객체 지향 접근으로 복잡함
        hanoi(mid, start, end, depth - 1);
    }
}

int main() {
    cin >> n;
    exper(n);
    if (n <= 20) hanoi(1, 2, 3, n);
    return 0;
}
