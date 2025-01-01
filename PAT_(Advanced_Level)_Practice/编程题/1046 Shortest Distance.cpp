// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805435700199424
#include <iostream>
using namespace std;
const int maxn = 100010;
int d[maxn] = {0}, sumD = 0;

int main(){
    int n, m, left, right;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        int temp;
        scanf("%d", &temp);
        sumD += temp;
        d[i] = sumD;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        scanf("%d%d", &left, &right);
        if (left > right) {
            swap(left, right);
        }
        int dist = d[right - 1] - d[left - 1];
        printf("%d\n", min(dist, sumD - dist));
    }
    return 0;
}