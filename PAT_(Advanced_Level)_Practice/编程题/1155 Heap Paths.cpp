// https://pintia.cn/problem-sets/994805342720868352/exam/problems/1071785408849047552
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1010;
int Node[maxn], level[maxn], n, pos = 1;
vector<int> path;
int numPath = 0, numMax = 0, numMin = 0;
bool invalid = false;

bool inc() {
    for (int i = path.size() - 1; i >= 1; i--) {
        if (Node[path[i]] > Node[path[i - 1]]) {
            return false;
        }
    }
    return true;
}

bool dec() {
    for (int i = path.size() - 1; i >= 1; i--) {
        if (Node[path[i]] < Node[path[i - 1]]) {
            return false;
        }
    }
    return true;
}

void DFS(int root) {
    path.push_back(root);
    if (root * 2 > n) {
        for (int i = 0; i < path.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", Node[path[i]]);
        }
        printf("\n");

        if (inc()) numMax++;
        else if (dec()) numMin++;
        else invalid = true;
        numPath++;
        path.pop_back();
        return;
    }
    if (root * 2 + 1 <= n) DFS(root * 2 + 1);
    if (root * 2 <= n) DFS(root * 2);
    path.pop_back();
}

void levelOrder(int root){
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        Node[now] = level[pos++];
        if (now * 2 <= n) q.push(now * 2);
        if (now * 2 + 1 <= n) q.push(now * 2 + 1);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", level + i);
    }
    levelOrder(1);
    DFS(1);

    // printf("%d--%d--%d\n", numPath, numMax, numMin);

    if (numMax == numPath) printf("Max Heap\n");
    else if (numMin == numPath) printf("Min Heap\n");
    else printf("Not Heap\n");
    return 0;
}