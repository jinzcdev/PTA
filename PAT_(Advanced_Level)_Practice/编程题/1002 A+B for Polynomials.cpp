// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805526272000000
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1010;
struct node {
    double c;
    int e;
} Node[maxn];
vector<int> ans;
bool vis[maxn] = {false};
bool cmp(int a, int b) {
    return a > b;
}
int main(){
    int k, n;
    double c;
    for (int i = 0; i < 2; i++){
        scanf("%d", &k);
        for (int j = 0; j < k; j++){
            scanf("%d%lf", &n, &c);
            Node[n].e = n;
            Node[n].c += c;
            if (!vis[n]) vis[n] = true;
            if (Node[n].c == 0) vis[n] = false;
        }
    }
    for (int i = 0; i < maxn; i++){
        if (vis[i]) {
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d", (int)ans.size());
    for (int i = 0; i < ans.size(); i++){
        printf(" %d %.1f", ans[i], Node[ans[i]].c);
    }
    return 0;
}