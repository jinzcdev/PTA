// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1071785664454127616
#include <iostream>
#include <cmath>
using namespace std;
int getLen(int number) {
    int cnt = 0;
    while (number != 0) {
        number /= 10;
        cnt++;
    }
    return cnt;
}
int main() {
    int m;
    scanf("%d", &m);
    while (m--) {
        int n = 1, k, rs;
        scanf("%d", &k);
        int product = k * k;
        bool flag = false;
        for ( ; n <= 9; n++) {
            rs = n * product;
            int len = getLen(k);
            int temp = rs % (int)pow(10, len);
            if (temp == k) {
                flag = true;
                break;
            }
        }
        if (flag == true) printf("%d %d\n", n, rs);
        else printf("No\n");
    }
    return 0;
}