// mod, 분할 정복
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

long long m, result = 0;
long long mod = 1000000007;
vector<pair<long long, long long>> dice; // first : N   second : S

void init() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        long long n, s;
        cin >> n >> s;
        dice.push_back(make_pair(n, s));
    }
}

long long exper(long long num, long long exp) {     // 분할 정복을 통해 빠르게 ^n 구하기
    if (exp == 1) return num;                       // 짝수면 반으로 나눠서 각각 구하고 다시 곱해주기
                                                    // 홀수면 하나 빼서 따로 곱해주기
    if (exp % 2 == 0) {
        long long half = exper(num, exp / 2);
        return (half * half) % mod;
    }
    else return (exper(num, exp -1) * num) % mod;
}

void expect() {
    for (int i = 0; i < dice.size(); i++) {
        long long n = dice[i].second, s = dice[i].first;
        long long g = gcd(n, s); // 최소 공배수로 나눠서 기약분수로 만들기
        n /= g;
        s /= g;
        result += (n * exper(s, mod - 2)) % mod;    // mod로 나눈 나머지로 바꿔서 수의 크기 줄이기
        result %= mod;                              // 모든 계산에 실행하기
    }
    return;
}

int main() {
    init();
    expect();
    cout << result << endl;
    return 0;
}
