// gcd(F(n), F(m)) = F(gcd(n, m)) -> 피보나치 함수의 성질
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

long long n, m;
const long long mod = 1000000007;
vector<vector<long long>> mat = {
    {1, 1},
    {1, 0}
};  // 2차원 배열보다 2차원 벡터로 시용하는게 편함
    // 벡터 내부에 long long으로 지정하면 자동으로 long long 형태로 저장됨
vector<vector<long long>> multiply(vector<vector<long long>> a, vector<vector<long long>> b) {
    vector<vector<long long>> new_mat(2, vector<long long>(2, 0));     // 크기를 직접 정해주면서 생성한다
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                new_mat[i][j] += (a[i][k] * b[k][j]) % mod;
                new_mat[i][j] %= mod;
            }
        }
    }
    return new_mat;
}

vector<vector<long long>> exper(vector<vector<long long>> matrix, long long exp) {
    if (exp == 1) return matrix;

    vector<vector<long long>> half = exper(matrix, exp / 2);
    vector<vector<long long>> result = multiply(half, half);    // half를 한 번만 구하고 제곱하는게 연산량이 줄어든다

    if (exp % 2 == 1) result = multiply(result, mat);           // 홀수는 나머지가 1이므로, half 제곱에 mat을 곱해주면 된다

    return result;
}

long long gcd(long long a, long long b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

int main() {
    cin >> n >> m;
    
    long long g = gcd(n, m);
    vector<vector<long long>> matG = exper(mat, g + 1);
    long long fibg = matG[1][1] % mod;
    
    cout << fibg << endl;
    return 0;
}
