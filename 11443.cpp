// 분할 정복 0 1 1 2 3
// Square_Sum(n) = A(n + 1) * A(n)

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
vector<vector<long long>> mat = {{1, 1}, {1, 0}};

vector<vector<long long>> multiply(vector<vector<long long>> a, vector<vector<long long>> b) {
    vector<vector<long long>> new_mat(2, vector<long long>(2));
    new_mat[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % mod;
    new_mat[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % mod;
    new_mat[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % mod;
    new_mat[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % mod;
    return new_mat;
}

vector<vector<long long>> exper(vector<vector<long long>> matrix, long long exp) {
    if (exp == 1) return mat;  // 기저 조건

    vector<vector<long long>> half = exper(matrix, exp / 2);
    vector<vector<long long>> result = multiply(half, half);

    if (exp % 2 == 1) {
        result = multiply(result, mat);
    }

    return result;
}

int main() {
    cin >> n;
    vector<vector<long long>> result = exper(mat, n + 1);
    cout << (result[0][1] * result[1][1]) % mod << endl;
    return 0;
}
