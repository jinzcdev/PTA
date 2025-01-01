// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805372601090048
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 110;
vector<int> tree[maxn];
int n, m;
int ans[maxn] = {0}, maxDepth = 0;

void DFS(int root, int depth){
    ans[depth]++;
    if (depth > maxDepth){
        maxDepth = depth;
    }
    for (int i = 0; i < tree[root].size(); i++){
        DFS(tree[root][i], depth + 1);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    int parent, num, child;
    for (int i = 0; i < m; i++){
        scanf("%d%d", &parent, &num);
        for (int j = 0; j < num; j++){
            scanf("%d", &child);
            tree[parent].push_back(child);
        }
    }
    DFS(1, 1);
    int max = 0, maxGen = 0;
    for (int i = 1; i <= maxDepth; i++){
        if (ans[i] > max){
            max = ans[i];
            maxGen = i;
        }
    }
    printf("%d %d\n", max, maxGen);
    return 0;
}