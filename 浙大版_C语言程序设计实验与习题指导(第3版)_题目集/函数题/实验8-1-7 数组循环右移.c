// https://pintia.cn/problem-sets/13/exam/problems/551
void reverse (int a[], int left, int right) {
    for (int i = left; i < (left + right + 1) / 2; i++) {
        int temp = a[i];
        a[i] = a[left + right - i];
        a[left + right - i] = temp;
    }
}
int ArrayShift( int a[], int n, int m ) {
    m = m % n;
    reverse(a, 0, n - m - 1);
    reverse(a, n - m, n - 1);
    reverse(a, 0, n - 1);
    return 0;
}