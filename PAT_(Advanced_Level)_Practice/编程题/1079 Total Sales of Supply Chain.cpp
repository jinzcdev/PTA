// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805388447170560
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 100010;
struct {
    int amount;   // the amount of product.
    int height;
    vector<int> children;
} node[maxn];

vector<int> retailer;

void BFS(int root){
    queue<int> q;
    q.push(root);
    node[root].height = 0;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        for (int i = 0; i < node[now].children.size(); i++){
            q.push(node[now].children[i]);
            node[node[now].children[i]].height = node[now].height + 1;
        }
    }
}

int main(){
    int n, k, temp;
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    for (int i = 0; i < n; i++){
        scanf("%d", &k);
        if (k == 0){
            scanf("%d", &temp);
            retailer.push_back(i);
            node[i].amount = temp;
        } else {
            for (int j = 0; j < k; j++){
                scanf("%d", &temp);
                node[i].children.push_back(temp);
            }
        }
    }
    BFS(0);
    double sum = 0.0;
    for (int i = 0; i < retailer.size(); i++){
        int index = retailer[i];
        sum += p * pow(1 + r / 100, node[index].height) * node[index].amount;
    }
    printf("%.1f", sum);
    return 0;
}