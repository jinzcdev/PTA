// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1038430130011897856
#include <bits/stdc++.h>
using namespace std;
struct node {
    int val;
    node *left, *right;
    node(int _val) : val(_val) { left = right = nullptr; }
};
vector<int> pre, in, ans;
node* build(int prel, int prer, int inl, int inr) {
    if (prel > prer) return nullptr;
    node* root = new node(pre[prel]);
    int k = inl;
    while (k <= inr && in[k] != pre[prel]) k++;
    int numleft = k - inl;
    root->left = build(prel + 1, prel + numleft, inl, k - 1);
    root->right = build(prel + numleft + 1, prer, k + 1, inr);
    return root;
}
node* lca(node* root, int u, int v) {
    if (root == nullptr || root->val == u || root->val == v) {
        return root;
    }
    node* left = lca(root->left, u, v);
    node* right = lca(root->right, u, v);
    if (left != nullptr && right != nullptr) {
        return root;
    }
    return left == nullptr ? right : left;
}
int main() {
    int n, m;
    cin >> n >> m;
    pre.resize(m);
    in.resize(m);
    unordered_set<int> st;
    for (int i = 0; i < m; i++) {
        cin >> in[i];
        st.insert(in[i]);
    }
    for (int i = 0; i < m; i++) cin >> pre[i];
    node* root = build(0, m - 1, 0, m - 1);
    int a, b;
    while (n--) {
        cin >> a >> b;
        if (st.find(a) == st.end() && st.find(b) == st.end()) {
            printf("ERROR: %d and %d are not found.\n", a, b);
        } else if (st.find(a) == st.end() || st.find(b) == st.end()) {
            printf("ERROR: %d is not found.\n", st.find(a) == st.end() ? a : b);
        } else {
            node* nd = lca(root, a, b);
            if (nd->val == a || nd->val == b) {
                printf("%d is an ancestor of %d.\n", nd->val, nd->val == a ? b : a);
            } else {
                printf("LCA of %d and %d is %d.\n", a, b, nd->val);
            }
        }
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int pre[N], in[N];
unordered_map<int, int> pos;
void lca(int prel, int prer, int inl, int inr, int u, int v) {
    if (prel > prer) return;
    int posR = pos[pre[prel]], posu = pos[u], posv = pos[v];
    if (posR > posu && posR > posv) lca(prel + 1, prel + posR - inl, inl, posR - 1, u, v);
    else if (posR < posu && posR < posv) lca(prel + posR - inl + 1, prer, posR + 1, inr, u, v);
    else if (posR == posu || posR == posv)
        printf("%d is an ancestor of %d.\n", pre[prel], posR == posu ? v : u);
    else if ((posR > posu && posR < posv) || (posR > posv && posR < posu))
        printf("LCA of %d and %d is %d.\n", u, v, pre[prel]);
}
int main() {
    int n, m, u, v;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &pre[i]);
    while (m--) {
        scanf("%d%d", &u, &v);
        if (pos[u] == 0 && pos[v] == 0) printf("ERROR: %d and %d are not found.\n", u, v);
        else if (pos[u] == 0 || pos[v] == 0) printf("ERROR: %d is not found.\n", pos[u] == 0 ? u : v);
        else lca(1, n, 1, n, u, v);
    }
    return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
vector<int> pre, in;
unordered_map<int, int> pos;
void lca(int prel, int inl, int inr, int u, int v) {
    if (inl > inr) return;
    int posRoot = pos[pre[prel]], posu = pos[u], posv = pos[v];
    if (posu < posRoot && posv < posRoot) lca(prel + 1, inl, posRoot - 1 - 1, u, v);
    else if (posu > posRoot && posv > posRoot) lca(prel + posRoot - inl, posRoot, inr, u, v);
    else if (posu == posRoot || posv == posRoot)
        printf("%d is an ancestor of %d.\n", pre[prel], posu == posRoot ? v : u);
    else
        printf("LCA of %d and %d is %d.\n", u, v, pre[prel]);
}
int main() {
    int m, n, u, v;
    scanf("%d%d", &m, &n);
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i + 1;
    }
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        if (pos[u] == 0 && pos[v] == 0) printf("ERROR: %d and %d are not found.\n", u, v);
        else if (pos[u] == 0 || pos[v] == 0) printf("ERROR: %d is not found.\n", pos[u] == 0 ? u : v);
        else lca(0, 0, n - 1, u, v);
    }
    return 0;
}
*/