// https://pintia.cn/problem-sets/434/problems/6104
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
void upAdjust(int *heap, int low, int high) {
    int i = high, j = i / 2;
    while (j >= low) {
        if (heap[i] >= heap[j]) break;
        swap(heap[i], heap[j]);
        i = j;
        j = i / 2;
    }
}
int main() {
    int heap[N], n, m, a, len = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &heap[++len]);
        upAdjust(heap, 1, len);
    }
    while (m--) {
        scanf("%d", &a);
        for (int i = a; i >= 1; i /= 2) {
            printf("%d", heap[i]);
            if (i != 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}