// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805284923359232
#include <iostream>
using namespace std;
int change(int *arr) {
    return arr[0] * 17 * 29 + arr[1] * 29 + arr[2];
}
int main() {
    int p[5], a[5], ans[5], ratio[3] = {1, 17, 29};
    scanf("%d.%d.%d %d.%d.%d", &p[0], &p[1], &p[2], &a[0], &a[1], &a[2]);
    if (change(p) > change(a)) {
        printf("-");
        swap(p, a);
    }
    for (int i = 2; i >= 0; i--) {
        if (a[i] >= p[i]) ans[i] = a[i] - p[i];
        else {
            ans[i] = a[i] - p[i] + ratio[i];
            a[i - 1]--;
        }
    }
    printf("%d.%d.%d", ans[0], ans[1], ans[2]);
    return 0;
}