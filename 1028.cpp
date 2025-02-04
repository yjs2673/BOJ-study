#include <iostream>
#include <vector>
using namespace std;

int r, c, result = 0;
int mine[760][760];
int ld[760][760] = {0,};
int rd[760][760] = {0,};
int lu[760][760] = {0,};
int ru[760][760] = {0,};

int small(int a, int b, int c, int d) {
    if (a <= b && a <= c && a <= d) return a;
    if (b <= a && b <= c && b <= d) return b;
    if (c <= a && c <= b && c <= d) return c;
    else return d;
}

void init() {
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= c; j++) {
            mine[i][j] = s[j - 1] - '0';
        }
    }
}

void set() {    // 테두리 좌표는 인덱스 계산이 r, c 범위를 넘으므로 처음부터 mine[][] 크기를 실제보다 크게 설정한다
                // 그래야 테두리 좌표의 ld rd lu ru 값이 제대로 0 or 1로 init이 된다
    for (int i = r; i > 0; i--) {
        for (int j = 1; j <= c; j++) {
            if (mine[i][j] == 1) {
                ld[i][j] = ld[i + 1][j - 1] + 1;
                rd[i][j] = rd[i + 1][j + 1] + 1;
            }
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (mine[i][j] == 1) {
                lu[i][j] = lu[i - 1][j - 1] + 1;
                ru[i][j] = ru[i - 1][j + 1] + 1;
            }
        }
    }
}

void dp() {     // 좌표를 다이아몬드의 중심으로 잡고, 위아래 꼭짓점을 기준으로 각각 ld, rd 값과 lu, ru 값을 판단
                // 4개의 값이 모두 같으면 그 값이 해당 다이아몬드의 크기다
                // 위아래 2가지로 나누기 & 4개의 값을 비교하므로 위에서 ld, rd를 판단할 때 lu, du보다
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int l = (result != 0) ? result : 1; // 중심을 기준으로 길이 맞추는게 잘못된건가?
            for (int k = l; k <= small(i - 1, r - i, j - 1, c - j) + 1; k++) { // 다이아 아래 꼭짓점
                int t = i + (k - 1) * 2;
                if (t > r + 1) break;
                if (mine[t][j] && lu[t][j] >= k && ru[t][j] >= k) result = k;
            }
            for (int k = l; k <= small(i - 1, r - i, j - 1, c - j) + 1; k++) { // 다이아 위 꼭짓점
                int t = i - (k - 1) * 2;
                if (t < 1) break;
                if (mine[t][j] && rd[t][j] >= k && ld[t][j] >= k) result = k;
            }
        }
    }
    cout << result << endl;
}

int main() {
    init();
    set();
    dp();
    return 0;
}
