// https://pintia.cn/problem-sets/15/exam/problems/710
#include <bits/stdc++.h>
using namespace std;
int polyProduct[2010], polySum[1010], poly[1010];
void print(int *arr, int len) {
    int i = len;
    while (i >= 0 && arr[i] == 0) i--;
    if (i < 0) {
        printf("0 0\n");
        return;
    }
    printf("%d %d", arr[i], i);
    for (int j = i - 1; j >= 0; j--)
        if (arr[j] != 0) printf(" %d %d", arr[j], j);
    printf("\n");
}
int main() {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        poly[b] = polySum[b] = a;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        for (int j = 0; j <= 1000; j++)
            if (poly[j] != 0) polyProduct[b + j] += a * poly[j];
        polySum[b] += a;
    }
    print(polyProduct, 2000);
    print(polySum, 1000);
    return 0;
}