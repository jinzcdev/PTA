// https://pintia.cn/problem-sets/16/exam/problems/type/7?problemSetProblemId=682
#include <bits/stdc++.h>
using namespace std;
const int N = 20;
struct node {
    int data;
    node *left, *right;
    node(int x) : data(x) { left = right = NULL; }
};
void insert(node*& root, int x) {
    if (root == NULL) {
        root = new node(x);
        return;
    }
    if (x < root->data) insert(root->left, x);
    else insert(root->right, x);
}
bool check(node* a, node* b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;
    return a->data == b->data && check(a->left, b->left) && check(a->right, b->right);
}
int main() {
    int n, m, a;
    while (scanf("%d", &n), n != 0) {
        scanf("%d", &m);
        node* root = NULL;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            insert(root, a);
        }
        while (m--) {
            node* tempR = NULL;
            for (int i = 0; i < n; i++) {
                scanf("%d", &a);
                insert(tempR, a);
            }
            printf("%s\n", check(root, tempR) ? "Yes" : "No");
        }
    }
    return 0;
}