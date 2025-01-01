// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1478634116941389824
#include <bits/stdc++.h>
using namespace std;
struct node {
    string id;
    int price, cnt, sum;
};
int main() {
    int n, max_sum = -1, max_cnt = -1;
    node a, b, tmp;
    scanf("%d", &n);
    while (n--) {
        cin >> tmp.id >> tmp.price >> tmp.cnt;
        tmp.sum = tmp.price * tmp.cnt;
        if (tmp.sum > max_sum) {
            max_sum = tmp.sum;
            b = tmp;
        }
        if (tmp.cnt > max_cnt) {
            max_cnt = tmp.cnt;
            a = tmp;
        }
    }
    printf("%s %d\n%s %d", a.id.c_str(), a.cnt, b.id.c_str(), b.sum);
    return 0;
}