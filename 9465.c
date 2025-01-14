// DP, 위, 아래, 선택 안함의 3가지 선택지를 연속하여 큰 값을 더하며 끝에서 제일 값이 큰 경우를 출력
#include <stdio.h>

int t;

int big(int a, int b) {
    return a > b ? a : b;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        
        int a[n], b[n], dp[2][n + 1];
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < n; i++) scanf("%d", &b[i]);
        
        dp[0][0] = a[0]; //dp[0] : a가 마지막으로 들어온 원소
        dp[1][0] = b[0]; //dp[1] : b가 마지막으로 들어온 원소
        dp[0][1] = dp[1][0] + a[1];
        dp[1][1] = dp[0][0] + b[1];
        
        for(int i = 2; i < n; i++) {
            dp[0][i] = big(dp[1][i-1] + a[i], dp[1][i-2] + a[i]);
            dp[1][i] = big(dp[0][i-1] + b[i], dp[0][i-2] + b[i]);
        }
        printf("%d\n", big(dp[0][n-1], dp[1][n-1]));
    }
    return 0;
}
