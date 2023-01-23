// https://pintia.cn/problem-sets/994805342720868352/problems/994805424153280512
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
struct node {
    int weight;
    vector<int> child;
} Node[N];
int n, m, w;
vector<int> path;
bool cmp(int a, int b) { return Node[a].weight > Node[b].weight; }
void dfs(int u, int sum) {
    if (sum > w) return;
    if (sum == w) {
        if (Node[u].child.size() != 0) return;
        for (int i = 0; i < path.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", Node[path[i]].weight);
        }
        printf("\n");
        return;
    }
    for (auto it : Node[u].child) {
        path.push_back(it);
        dfs(it, sum + Node[it].weight);
        path.pop_back();
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &w);
    for (int i = 0; i < n; i++) scanf("%d", &Node[i].weight);
    int parent, child, k;
    while (m--) {
        scanf("%d%d", &parent, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &child);
            Node[parent].child.push_back(child);
        }
        sort(Node[parent].child.begin(), Node[parent].child.end(), cmp);
    }
    path.push_back(0);
    dfs(0, Node[0].weight);
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
struct node {
    int weight;
    vector<int> child;
} Node[N];
int n, m, w;
vector<int> path;
vector<vector<int> > ans;
bool cmp(int a, int b) { return Node[a].weight > Node[b].weight; }
void dfs(int u) {
    path.push_back(u);
    if (Node[u].child.size() == 0) {
        int tempw = 0;
        for (auto it : path) tempw += Node[it].weight;
        if (tempw == w) ans.push_back(path);
        path.pop_back();
        return;
    }
    for (auto it : Node[u].child) dfs(it);
    path.pop_back();
}
int main() {
    scanf("%d%d%d", &n, &m, &w);
    for (int i = 0; i < n; i++) scanf("%d", &Node[i].weight);
    int parent, child, k;
    while (m--) {
        scanf("%d%d", &parent, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &child);
            Node[parent].child.push_back(child);
        }
        sort(Node[parent].child.begin(), Node[parent].child.end(), cmp);
    }
    dfs(0);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            if (j != 0) printf(" ");
            printf("%d", Node[ans[i][j]].weight);
        }
        printf("\n");
    }
    return 0;
}
*/