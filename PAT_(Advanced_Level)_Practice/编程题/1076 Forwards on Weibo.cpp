// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805392092020736
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1010;
struct node {
    int id;
    int layer;
} Node;
vector<node> G[maxn];
int n, l;
bool inq[maxn];

int BFS(int start){
    int ans = 0;
    memset(inq, false, n + 1);

    queue<node> q;
    Node.id = start;
    Node.layer = 1;
    q.push(Node);
    while (!q.empty()){
        node now = q.front();
        q.pop();
        int parent = now.id;
        inq[parent] = true;
        for (int i = 0; i < G[parent].size(); i++){
            node next = G[parent][i];
            next.layer = now.layer + 1;
            if (!inq[next.id] && now.layer <= l){
                q.push(next);
                inq[next.id] = true;
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    scanf("%d%d",&n, &l);
    int m, id, k;
    for (int i = 1; i <= n; i++){
        scanf("%d", &m);
        Node.id = i;
        Node.layer = 1;
        for (int j = 0; j < m; j++){
            scanf("%d", &id);
            G[id].push_back(Node);
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        scanf("%d", &id);
        printf("%d\n", BFS(id));
    }
    return 0;
}