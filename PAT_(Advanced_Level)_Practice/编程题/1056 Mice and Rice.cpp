// https://pintia.cn/problem-sets/994805342720868352/problems/994805419468242944
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1010;
struct mouse {
    int weight;
    int R;
} mouse[maxn];
int main(){
    int np, ng, order;
    scanf("%d%d", &np, &ng);
    for (int i = 0; i < np; i++) {
        scanf("%d", &mouse[i].weight);
    }
    queue<int> q;
    for (int i = 0; i < np; i++) {
        scanf("%d", &order);
        q.push(order);
    }
    int temp = np, group;
    while (q.size() != 1) {
        if (temp % ng == 0) group = temp / ng;
        else group = temp / ng + 1;
        for (int i = 0; i < group; i++) {
            int k = q.front();
            for (int j = 0; j < ng; j++) {
                if (i * ng + j >= temp) break;
                if (mouse[q.front()].weight > mouse[k].weight) {
                    k = q.front();
                }
                mouse[q.front()].R = group + 1;
                q.pop();
            }
            q.push(k);
        }
        temp = group;
    }
    mouse[q.front()].R = 1;
    for (int i = 0; i < np; i++) {
        if (i != 0) printf(" ");
        printf("%d", mouse[i].R);
    }
    return 0;
}