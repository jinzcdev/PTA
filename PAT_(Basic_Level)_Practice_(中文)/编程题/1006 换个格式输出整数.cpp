// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805318855278592
#include <bits/stdc++.h>
using namespace std;
int main() {
    int number, a[5];
    char ch[3] = {'#', 'S', 'B'};
    cin >> number;
    int len = 0;
    while (number != 0) {
        a[len++] = number % 10;
        number /= 10;
    }
    for (int i = len - 1; i > 0; i--)
        for (int j = 0; j < a[i]; j++) printf("%c", ch[i]);
    for (int i = 1; i <= a[0]; i++) printf("%d", i);
    return 0;
}

// n = int(input())
// print('B' * (n // 100) + 'S' * ((n % 100) // 10) + ''.join(list(map(str, range(1, n % 10 + 1)))))