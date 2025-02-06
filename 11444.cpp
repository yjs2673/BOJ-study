// 분할 정복, 행렬을 이용한 피보나치 수 구하기
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

long long n;
const long long mod = 1000000007;
vector<vector<long long>> mat = {{1, 1}, {1, 0}};   // 2차원 배열보다 2차원 벡터로 시용하는게 편함
                                                    // 벡터 내부에 long long으로 지정하면 자동으로 long long 형태로 저장됨
vector<vector<long long>> multiply(vector<vector<long long>> a, vector<vector<long long>> b) {
    vector<vector<long long>> new_mat(2, vector<long long>(2));     // 크기를 직접 정해주면서 생성한다
    new_mat[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % mod;
    new_mat[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % mod;
    new_mat[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % mod;
    new_mat[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % mod;
    return new_mat;
}

vector<vector<long long>> exper(vector<vector<long long>> matrix, long long exp) {
    if (exp == 1) return mat;

    vector<vector<long long>> half = exper(matrix, exp / 2);
    vector<vector<long long>> result = multiply(half, half);        // half를 한 번만 구하고 제곱하는게 연산량이 줄어든다

    if (exp % 2 == 1) {
        result = multiply(result, mat);                             // 홀수는 나머지가 1이므로, half 제곱에 mat을 곱해주면 된다
    }

    return result;
}

int main() {
    cin >> n;
    vector<vector<long long>> result = exper(mat, n + 1);
    cout << result[1][1] << endl;
    return 0;
}
