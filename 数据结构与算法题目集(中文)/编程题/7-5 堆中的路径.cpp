// https://pintia.cn/problem-sets/15/exam/problems/type/7?problemSetProblemId=713
#include <bits/stdc++.h>
using namespace std;
vector<int> heap;
int len = 0;
void upAdjust(int low, int high) {
    int i = high, j = i / 2;
    while (j >= low) {
        if (heap[i] >= heap[j]) break;
        swap(heap[i], heap[j]);
        i = j;
        j = i / 2;
    }
}
void insertHeap(int x) {
    heap[++len] = x;
    upAdjust(1, len);
}
int main() {
    int n, m, a, pos;
    scanf("%d%d", &n, &m);
    heap.resize(n + 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        insertHeap(a);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &pos);
        for (int j = pos; j >= 1; j /= 2) {
            printf("%d", heap[j]);
            if (j != 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}