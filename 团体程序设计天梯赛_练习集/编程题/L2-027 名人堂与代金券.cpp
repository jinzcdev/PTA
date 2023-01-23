// https://pintia.cn/problem-sets/994805046380707840/problems/994805055176163328
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
struct node {
    string name;
    int rank, score;
} Node[N];
bool cmp(node& a, node& b) {
    return a.score != b.score ? a.score > b.score : a.name < b.name;
}
int main() {
    int n, g, k, score, num = 1, sum = 0;
    string name;
    scanf("%d%d%d", &n, &g, &k);
    for (int i = 1; i <= n; i++) {
        cin >> Node[i].name >> Node[i].score;
        if (Node[i].score >= g) sum += 50;
        else if (Node[i].score >= 60) sum += 20;
    }
    sort(Node + 1, Node + n + 1, cmp);
    Node[1].rank = 1;
    for (int i = 2; i <= n; i++) {
        if (Node[i].score == Node[i - 1].score) Node[i].rank = Node[i - 1].rank;
        else Node[i].rank = i;
    }
    printf("%d\n", sum);
    for (int i = 1; i <= n; i++) {
        if (Node[i].rank > k) break;
        printf("%d %s %d\n", Node[i].rank, Node[i].name.c_str(), Node[i].score);
    }
    return 0;
}