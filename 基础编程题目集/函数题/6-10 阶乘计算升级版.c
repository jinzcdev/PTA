// https://pintia.cn/problem-sets/14/exam/problems/742
void Print_Factorial(const int N) {
    if (N < 0)
        printf("Invalid input\n");
    else if (N <= 1)
        printf("1\n");
    else {
        int ans[10000] = {0};
        int len = 1;
        ans[0] = 1;
        for (int i = 2; i <= N; i++) {
            int carry = 0, tempLen = len;
            len = 0;
            for (int j = 0; j < tempLen; j++) {
                int temp = ans[j] * i + carry;
                ans[len++] = temp % 10;
                carry = temp / 10;
            }
            while (carry != 0) {
                ans[len++] = carry % 10;
                carry /= 10;
            }
        }
        for (int i = len - 1; i >= 0; i--) {
            printf("%d", ans[i]);
        }
    }
}