// https://pintia.cn/problem-sets/994805342720868352/problems/994805526272000000
#include <cstdio>
int main() {
    double p[1010] = {0}, c;
    int k, e, cnt = 0;
    for (int i = 0; i < 2; i++) {
        scanf("%d", &k);
        while (k--) {
            scanf("%d%lf", &e, &c);
            if (p[e] == 0) cnt++;
            p[e] += c;
            if (p[e] == 0) cnt--;   // 如果系数变为0, 则不计数
        }
    }
    printf("%d", cnt);
    for (int e = 1001; e >= 0; e--) {
        if (p[e] != 0) printf(" %d %.1f", e, p[e]);
    }
    return 0;
}

/*#include <cstdio>
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
            if (!vis[n]) vis[n] = true;         // 该指数出现过
            if (Node[n].c == 0) vis[n] = false; // 该指数的系数为0, 则删去该数
        }
    }
    for (int i = 0; i < maxn; i++){
        if (vis[i]) ans.push_back(i);
    }
    sort(ans.begin(), ans.end(), cmp);          // 按指数从大到小排序
    printf("%d", (int)ans.size());
    for (int i = 0; i < ans.size(); i++){
        printf(" %d %.1f", ans[i], Node[ans[i]].c);
    }
    return 0;
}*/

/*
#include <cstdio>
const int maxn = 1010;
double p[maxn];
int main(){
    int k, e, cnt = 0;
    double c;
    for (int i = 0; i < 2; i++){
        scanf("%d", &k);
        for (int j = 0; j < k; j++){
            scanf("%d %lf", &e, &c);
            p[e] += c;
        }
    }
    for (int i = 0; i < maxn; i++){
        if (p[i] != 0) cnt++;
    }
    printf("%d", cnt);
    for (int i = maxn - 1; i >= 0; i--){
        if (p[i] != 0) printf(" %d %.1f", i, p[i]);
    }
    return 0;
}
*/