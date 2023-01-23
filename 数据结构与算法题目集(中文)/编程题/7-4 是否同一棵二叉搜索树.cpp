// https://pintia.cn/problem-sets/15/problems/712
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left, *right;
    node(int _x) : data(_x) { left = right = nullptr; }
};
void insert(node *&root, int x) {
    if (root == nullptr) {
        root = new node(x);
        return;
    }
    if (x <= root->data) insert(root->left, x);
    else insert(root->right, x);
}
bool isIdentical(node *t1, node *t2) {
    if (t1 == nullptr && t2 == nullptr) return true;
    if (t1 == nullptr || t2 == nullptr) return false;
    if (t1->data != t2->data) return false;
    return isIdentical(t1->left, t2->left) && isIdentical(t1->right, t2->right);
}
int main() {
    int n, l, x;
    while (scanf("%d", &n)) {
        if (n == 0) break;
        scanf("%d", &l);
        node *t1 = nullptr;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            insert(t1, x);
        }
        while (l--) {
            node *t2 = nullptr;
            for (int i = 0; i < n; i++) {
                scanf("%d", &x);
                insert(t2, x);
            }
            printf("%s\n", isIdentical(t1, t2) ? "Yes" : "No");
        }
    }
    return 0;
}