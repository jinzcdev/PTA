// https://pintia.cn/problem-sets/13/problems/581
void printdigits(int n) {
    if (n < 10) {
        printf("%d\n", n);
        return 0;
    }
    printdigits(n / 10);
    printf("%d\n", n % 10);
}