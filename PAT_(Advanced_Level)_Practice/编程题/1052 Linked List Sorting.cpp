// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805425780670464
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
struct node {
    int adr, data, next;
} L[N];
bool cmp(node &a, node &b) { return a.data < b.data; }
int main() {
    int n, head, adr, data, next;
    scanf("%d%d", &n, &head);
    for (int i = 0; i < n; i++) {
        scanf("%d", &adr);
        scanf("%d%d", &L[adr].data, &L[adr].next);
        L[adr].adr = adr;
    }
    vector<node> l;
    for (int p = head; p != -1; p = L[p].next) l.push_back(L[p]);
    if (l.size() == 0) {
        printf("0 -1");
        return 0;
    }
    sort(l.begin(), l.end(), cmp);
    printf("%d %05d\n", l.size(), l[0].adr);
    for (int i = 0; i < l.size() - 1; i++)
        printf("%05d %d %05d\n", l[i].adr, l[i].data, l[i + 1].adr);
    printf("%05d %d -1\n", l[l.size() - 1].adr, l[l.size() - 1].data);
    return 0;
}
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// const int maxn = 100010;
// struct node{
//     int address, data, next;
//     bool flag;
// } L[maxn];

// bool cmp(node a, node b){
//     if (!a.flag || !b.flag){
//         return a.flag > b.flag;     // 标记过的元素放到数组前端
//     }else{
//         return a.data < b.data;     // 均为有效结点则数值较小者排在前
//     }
// }

// int main(){
//     for (int i = 0; i < maxn; i++){
//         L[i].flag = false;
//     }
//     int n, begin;
//     scanf("%d%d", &n, &begin);
//     for (int i = 0; i < n; i++){
//         int address;
//         scanf("%d", &address);
//         scanf("%d%d", &L[address].data, &L[address].next);
//         L[address].address = address;
//     }
//     int cnt = 0;
//     for (int p = begin; p != -1; p = L[p].next){    // 输出的数据中存在无效结点, 通过flag标记是否有效
//         L[p].flag = true;
//         cnt++;
//     }

//     if (cnt == 0){          // 特殊情况, 直接输出结果
//         printf("0 -1");
//     }else{
//         sort(L, L + maxn, cmp);
//         printf("%d %05d\n", cnt, L[0].address);
//         for (int i = 0; i < cnt; i++){
//             if (i < cnt - 1){
//                 printf("%05d %d %05d\n", L[i].address, L[i].data, L[i + 1].address);
//             }else{
//                 printf("%05d %d -1", L[i].address, L[i].data);
//             }
//         }
//     }
//     return 0;
// }