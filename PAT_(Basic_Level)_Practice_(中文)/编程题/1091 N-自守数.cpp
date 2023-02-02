// https://pintia.cn/problem-sets/994805260223102976/exam/problems/1071785664454127616
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a;
    cin >> n;
    while (n--) {
        cin >> a;
        bool flag = false;
        for (int k = 1; k < 10; k++) {
            int tmp = k * a * a;
            if ((tmp - a) % (int)pow(10, to_string(a).length()) == 0) {
                printf("%d %d\n", k, tmp);
                flag = true;
                break;
            }
        }
        if (!flag) printf("No\n");  
    }
    return 0;
}