// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805342821531648
#include <cstdio>
const int maxn = 1010;
int Node[maxn], n, m, cnt;

bool isMaxHeap(int root) {
    if (root * 2 > n) { // 为叶子节点, 一定是大顶堆或小顶堆
        return true;
    } else if (root * 2 + 1 <= n) {     // 左右孩子都存在
        return Node[root] >= Node[root * 2] && Node[root] >= Node[root * 2 + 1]
        && isMaxHeap(root * 2) && isMaxHeap(root * 2 + 1);
    } else {
        return Node[root] >= Node[root * 2] && isMaxHeap(root * 2);
    }
}

bool isMinHeap(int root) {
    if (root * 2 > n) { // 为叶子节点, 一定是大顶堆或小顶堆
        return true;
    } else if (root * 2 + 1 <= n) {     // 左右孩子都存在
        return Node[root] <= Node[root * 2] && Node[root] <= Node[root * 2 + 1]
        && isMinHeap(root * 2) && isMinHeap(root * 2 + 1);
    } else {
        return Node[root] <= Node[root * 2] && isMinHeap(root * 2);
    }
}

void postOrder(int root) {
    if (root > n) return;
    postOrder(root * 2);
    postOrder(root * 2 + 1);
    printf("%d", Node[root]);
    if (++cnt < n) printf(" ");
}

int main() {
    scanf("%d%d", &m, &n);
    while (m--) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", Node + i);
        }
        if (isMaxHeap(1)) {
            printf("Max Heap\n");
        } else if (isMinHeap(1)) {
            printf("Min Heap\n");
        } else {
            printf("Not Heap\n");
        }
        cnt = 0;
        postOrder(1);
        printf("\n");
    }
    return 0;
}