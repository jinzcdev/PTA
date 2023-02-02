// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805349394006016
#include <bits/stdc++.h>
using namespace std;
const int N = 35;
int post[N], in[N], maxDepth = -1;
vector<int> ans[N];
void create(int postl, int postr, int inl, int inr, int depth) {
    if (postl > postr) return;
    maxDepth = max(maxDepth, depth);
    ans[depth].push_back(post[postr]);
    int k = inl;
    while (k <= inr && in[k] != post[postr]) k++;
    int numleft = k - inl;
    create(postl, postl + numleft - 1, inl, k - 1, depth + 1);
    create(postl + numleft, postr - 1, k + 1, inr, depth + 1);
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    create(0, n - 1, 0, n - 1, 0);
    printf("%d", ans[0][0]);
    for (int i = 1; i <= maxDepth; i++) {
        if (i % 2 == 0) reverse(ans[i].begin(), ans[i].end());
        for (auto it : ans[i]) printf(" %d", it);
    }
    return 0;
}

/*
// https://pintia.cn/problem-sets/994805342720868352/problems/994805349394006016
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data, depth;
    node *lchild, *rchild;
};
vector<int> in, post;
vector<node*> ans[35];
int n, depth = 0;
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
    in.resize(n); post.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    node* root = create(0, n - 1, 0, n - 1);
    bfs(root);
    printf("%d", root->data);
    for (int i = 2; i <= depth; i++) {
        if (i % 2 == 0) for (int j = 0; j < ans[i].size(); j++) printf(" %d", ans[i][j]->data);
        else for (int j = ans[i].size() - 1; j >= 0; j--) printf(" %d", ans[i][j]->data);
    }
    return 0;
}
*/