// https://pintia.cn/problem-sets/12/problems/336
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void reverse(int *a, int n) {
    for (int i = 0; i < n / 2; i++) {
        swap(&a[i], &a[n - i - 1]);
    }
}
int ArrayShift(int a[], int n, int m) {
    m = m % n;
    if (m == 0) return 0;
    reverse(a, n - m);
    reverse(a + n - m, m);
    reverse(a, n);
    return 0;
}