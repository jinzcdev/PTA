// https://pintia.cn/problem-sets/13/problems/580
void dectobin(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    if (n / 2 != 0) {
        dectobin(n / 2);
    }
    printf("%d", n % 2);
}