// https://pintia.cn/problem-sets/994805342720868352/problems/994805342821531648
#include <bits/stdc++.h>
using namespace std;
int m, n, cnt = 0, heap[1010];
void postOrder(int i) {
    if (i > n) return;
    postOrder(i * 2);
    postOrder(i * 2 + 1);
    printf("%d", heap[i]);
    if (++cnt < n) printf(" ");
}
int main() {
    scanf("%d%d", &m, &n);
    while (m--) {
        for (int j = 1; j <= n; j++) scanf("%d", &heap[j]);
        bool isMaxHeap = true, isMinHeap = true;
        for (int i = 2; i <= n; i++) {
            if (heap[i] > heap[i / 2]) isMaxHeap = false;
            if (heap[i] < heap[i / 2]) isMinHeap = false;
        }
        if (!isMaxHeap && !isMinHeap) printf("Not Heap\n");
        else printf("%s\n", isMaxHeap ? "Max Heap" : "Min Heap");
        cnt = 0;
        postOrder(1);
        printf("\n");
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
vector<int> heap;
bool isMaxHeap(int i) {
    if (i > n || i * 2 > n) return true;
    if (heap[i] < heap[i * 2] || (i * 2 + 1 <= n && heap[i] < heap[i * 2 + 1]))
        return false;
    return isMaxHeap(i * 2) && isMaxHeap(i * 2 + 1);
}
bool isMinHeap(int i) {
    if (i > n || i * 2 > n) return true;
    if (heap[i] > heap[i * 2] || (i * 2 + 1 <= n && heap[i] > heap[i * 2 + 1]))
        return false;
    return isMinHeap(i * 2) && isMinHeap(i * 2 + 1);
}
void postOrder(int i) {
    if (i > n) return;
    postOrder(i * 2);
    postOrder(i * 2 + 1);
    printf("%d", heap[i]);
    if (++cnt < n) printf(" ");
}
int main() {
    cin >> m >> n;
    heap.resize(n + 1);
    for (int i = 0; i < m; i++) {
        for (int i = 1; i <= n; i++) scanf("%d", &heap[i]);
        if (isMaxHeap(1)) printf("Max Heap\n");
        else if (isMinHeap(1)) printf("Min Heap\n");
        else printf("Not Heap\n");
        cnt = 0;
        postOrder(1);
        printf("\n");
    }
    return 0;
}
*/