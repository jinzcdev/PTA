// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1729419732192542722
#include <bits/stdc++.h>
using namespace std;
struct node {
    int val;
    vector<node*> children;
    node(int _val) { val = _val; }
};

node* build(vector<string>& v, int l, int r, int depth) {
    if (l > r) return nullptr;
    node* root = new node(stoi(v[l++]));
    vector<int> nums;
    for (int i = l; i <= r; i++) {
        int d = v[i].size() - 4;
        if (d == depth) {
            nums.push_back(i);
        }
    }
    if (nums.empty()) {
        return root;
    }
    for (int i = 0; i < nums.size() - 1; i++) {
        root->children.push_back(build(v, nums[i], nums[i + 1] - 1, depth + 1));
    }
    root->children.push_back(build(v, *nums.rbegin(), r, depth + 1));
    return root;
}
vector<int> path, ans;
void dfs(node* root, int target) {
    if (!root) return;
    if (root->val == target) {
        ans = path;
        ans.push_back(target);
        return;
    }
    path.push_back(root->val);
    for (const auto& it : root->children) {
        dfs(it, target);
    }
    path.pop_back();
}
int main() {
    int n;
    cin >> n;
    string s;
    vector<string> v(n);
    unordered_set<int> vis;
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, v[i]);
        vis.insert(stoi(v[i]));
    }
    node* root = build(v, 0, n - 1, 1);
    int k, x;
    cin >> k;
    while (k--) {
        cin >> x;
        if (vis.find(x) == vis.end()) {
            printf("Error: %04d is not found.\n", x);
        } else {
            path.clear();
            dfs(root, x);
            for (int i = 0; i < ans.size(); i++) {
                if (i != 0) printf("->");
                printf("%04d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}