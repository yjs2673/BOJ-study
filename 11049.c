// DP, 행렬곱
#include <stdio.h>
#define max 2147483647;
int n, min = max;
int matrix[501][2];
int sum[501][501];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &matrix[i][0], &matrix[i][1]);
        sum[i][i] = 0;
    }
    
    for(int l = 2; l <= n; l++) {
        for(int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            sum[i][j] = max;
            for(int k = i; k <= j - 1; k++) {
                int q = sum[i][k] + sum[k + 1][j] + matrix[i][0]*matrix[k][1]*matrix[j][1];
                if(q < sum[i][j]) {
                    sum[i][j] = q;
                    min = q;
                }
            }
        }
    }
    
    printf("%d\n", min);
    return 0;
}
