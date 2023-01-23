// https://pintia.cn/problem-sets/13/problems/446
#include <stdio.h>
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int max(int n) {
    int a[3] = {0};
    for (int i = 0; i < 3; i++) {
        a[i] = n % 10;
        n /= 10;
    }
    if (a[0] < a[1]) swap(a, a + 1);
    if (a[0] < a[2]) swap(a, a + 2);
    if (a[1] < a[2]) swap(a + 1, a + 2);
    return a[0] * 100 + a[1] * 10 + a[2];
}
int reverse(int n) {
    int a = 0;
    while (n) {
        a = a * 10 + n % 10;
        n /= 10;
    }
    return a;
}
int main() {
    int a, cnt = 1;
    scanf("%d", &a);
    while (1) {
        int x = max(a), y = reverse(x);
        if (x < y) {
            int tmp = x;
            x = y;
            y = tmp;
        }
        printf("%d: %d - %d = %d\n", cnt++, x, y, x - y);
        a = x - y;
        if (a == 495) break;
    }
    return 0;
}