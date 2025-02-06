// 분할 정복, 행렬을 이용한 피보나치 수 구하기
// F(n) = F(n - 1) + F(n - 2) + 1
/*
 1 1 1
 1 0 0
 0 0 1 의 거듭제곱

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

long long a, b;
const long long mod = 1000000000;
vector<vector<long long>> mat = {
    {1, 1, 1},
    {1, 0, 0},
    {0, 0, 1}
};   // 2차원 배열보다 2차원 벡터로 시용하는게 편함
                                                    // 벡터 내부에 long long으로 지정하면 자동으로 long long 형태로 저장됨
vector<vector<long long>> multiply(vector<vector<long long>> a, vector<vector<long long>> b) {
    vector<vector<long long>> new_mat(3, vector<long long>(3, 0));     // 크기를 직접 정해주면서 생성한다
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                new_mat[i][j] += (a[i][k] * b[k][j]) % mod;
                new_mat[i][j] %= mod;
            }
        }
    }
    return new_mat;
}

vector<vector<long long>> exper(vector<vector<long long>> matrix, long long exp) {
    if (exp == 1) return mat;

    vector<vector<long long>> half = exper(matrix, exp / 2);
    vector<vector<long long>> result = multiply(half, half);    // half를 한 번만 구하고 제곱하는게 연산량이 줄어든다

    if (exp % 2 == 1) result = multiply(result, mat);           // 홀수는 나머지가 1이므로, half 제곱에 mat을 곱해주면 된다

    return result;
}

long long fibsum(long long n) {
    if (n <= 2) return n;

    vector<vector<long long>> new_mat = exper(mat, n - 2);
    return (2 * new_mat[0][0] + new_mat[0][1] + new_mat[0][2]) % mod;
}

int main() {
    cin >> a >> b;
    long long result = (fibsum(b) - fibsum(a - 1) + mod) % mod; // 결과 값 음수 방지
    cout << result << endl;
    return 0;
} */

// 분할 정복
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
