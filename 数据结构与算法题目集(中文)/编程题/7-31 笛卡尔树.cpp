// https://pintia.cn/problem-sets/15/exam/problems/858
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
struct node {
    int k1, k2, left, right;
} Node[N];
bool isBST(int u, int lower, int upper) {
    if (u == -1) return true;
    if (Node[u].k1 < lower || Node[u].k1 > upper) return false;
    if (Node[u].left != -1 && Node[u].k1 <= Node[Node[u].left].k1) return false;
    if (Node[u].right != -1 && Node[u].k1 >= Node[Node[u].right].k1) return false;
    return isBST(Node[u].left, lower, Node[u].k1) && isBST(Node[u].right, Node[u].k1, upper);
}
bool isMinHeap(int u) {
    if (u == -1) return true;
    if (Node[u].left == -1 && Node[u].right == -1) return true;
    if (Node[u].left != -1 && Node[u].k2 >= Node[Node[u].left].k2) return false;
    if (Node[u].right != -1 && Node[u].k2 >= Node[Node[u].right].k2) return false;
    return isMinHeap(Node[u].left) && isMinHeap(Node[u].right);
}
int main() {
    int n, k1, k2, left, right;
    scanf("%d", &n);
    unordered_map<int, bool> vis;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &k1, &k2, &left, &right);
        Node[i] = {k1, k2, left, right};
        vis[left] = vis[right] = true;
    }
    int root = 0;
    while (root < n && vis[root]) root++;
    printf("%s\n", isBST(root, INT_MIN, INT_MAX) && isMinHeap(root) ? "YES" : "NO");
    return 0;
}