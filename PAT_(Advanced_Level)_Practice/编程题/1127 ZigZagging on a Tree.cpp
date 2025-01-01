// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805349394006016
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data, depth;
    node *lchild, *rchild;
};
vector<int> in, post;
vector<node*> ans[35];
int n, cnt = 0, depth = 0;
node* create(int postL, int postR, int inL, int inR) {
    if (postL > postR) return NULL;
    node* root = new node;
    root->data = post[postR];
    root->lchild = root->rchild = NULL;
    int k = inL;
    while (in[k] != post[postR]) k++;
    int numLeft = k - inL;
    root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
    root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
    return root;
}
void bfs(node* root) {
    if (root == NULL) return;
    queue<node*> q;
    q.push(root);
    root->depth = 1;
    while (!q.empty()) {
        node* now = q.front();
        q.pop();
        ans[now->depth].push_back(now);
        depth = now->depth;
        if (now->lchild != NULL) {
            now->lchild->depth = depth + 1;
            q.push(now->lchild);
        }
        if (now->rchild != NULL) {
            now->rchild->depth = depth + 1;
            q.push(now->rchild);
        }
    }
}
int main() {
    scanf("%d", &n);
    in.resize(n);
    post.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    node* root = create(0, n - 1, 0, n - 1);
    bfs(root);
    for (int i = 1; i <= depth; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < ans[i].size(); j++) {
                printf("%d", ans[i][j]->data);
                if (++cnt < n) printf(" ");
            }
        } else {
            for (int j = ans[i].size() - 1; j >= 0; j--) {
                printf("%d", ans[i][j]->data);
                if (++cnt < n) printf(" ");
            }
        }
    }
    return 0;
}