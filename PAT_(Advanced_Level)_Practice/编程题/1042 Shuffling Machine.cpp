// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805442671132672
#include <bits/stdc++.h>
using namespace std;
const int N = 55;
char color[6] = "SHCDJ";
int main() {
    int k;
    scanf("%d", &k);
    vector<int> card(N), tmp(N), next(N);
    for (int i = 1; i <= 54; i++) card[i] = i;  // 初始化当前牌编号从1-54, 便于获取花色是牌值
    for (int i = 1; i <= 54; i++) scanf("%d", &next[i]);
    while (k--) {
        for (int i = 1; i <= 54; i++) tmp[next[i]] = card[i];  // 按顺序移动到新的暂存数组中
        card = tmp;
    }
    for (int i = 1; i <= 54; i++) {
        printf("%c%d", color[(card[i] - 1) / 13], (card[i] - 1) % 13 + 1);
        if (i < 54) printf(" ");
    }
    return 0;
}