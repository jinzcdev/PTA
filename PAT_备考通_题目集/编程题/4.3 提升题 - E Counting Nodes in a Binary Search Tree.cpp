// https://pintia.cn/problem-sets/1526027869896364032/exam/problems/type/7?problemSetProblemId=1526208391570313216
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data, depth;
    node *left, *right;
    node(int a) : data(a) { left = right = NULL; };
};
int maxDepth = -1, cntDepth[1005] = {0};
void insert(node *&root, int x) {
    if (root == NULL) {
        root = new node(x);
        return;
    }
    if (x <= root->data) insert(root->left, x);
    else insert(root->right, x);
}
void bfs(node *root) {
    queue<node *> q;
    root->depth = 1;
    q.push(root);
    while (!q.empty()) {
        node *now = q.front();
        q.pop();
        cntDepth[now->depth]++;
        maxDepth = max(maxDepth, now->depth);
        if (now->left != NULL) {
            now->left->depth = now->depth + 1;
            q.push(now->left);
        }
        if (now->right != NULL) {
            now->right->depth = now->depth + 1;
            q.push(now->right);
        }
    }
}
int main() {
    int n, x;
    scanf("%d", &n);
    node *root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(root, x);
    }
    bfs(root);
    printf("%d + %d = %d\n", cntDepth[maxDepth], cntDepth[maxDepth - 1],
           cntDepth[maxDepth] + cntDepth[maxDepth - 1]);
    return 0;
}