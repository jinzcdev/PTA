// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805376476626944
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
struct node{
    vector<int> child;
} Node[maxn];

int n, cnt = 0;
double p, r, maxDepth = 0;
void DFS(int root, int depth){
    if (Node[root].child.size() == 0){
        if (depth > maxDepth){
            maxDepth = depth;
            cnt = 1;
        } else if (depth == maxDepth){
            cnt++;
        }
        return;
    }
    for (int i = 0; i < Node[root].child.size(); i++){
        DFS(Node[root].child[i], depth + 1);
    }
}

int main(){
    scanf("%d%lf%lf", &n, &p, &r);
    int root, parent;
    for (int i = 0; i < n; i++){
        scanf("%d", &parent);
        if (parent != -1){
            Node[parent].child.push_back(i);
        } else {
            root = i;
        }
    }
    DFS(root, 0);
    printf("%.2f %d", p * pow(1 + r / 100, maxDepth), cnt);
    return 0;
}