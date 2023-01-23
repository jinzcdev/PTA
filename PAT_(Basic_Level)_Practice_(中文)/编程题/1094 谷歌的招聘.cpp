// https://pintia.cn/problem-sets/994805260223102976/problems/1071785997033074688
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    for (int i = 0; i <= n - k; i++) {
        string number = s.substr(i, k);
        if (isPrime(stoi(number))) {
            cout << number;
            return 0;
        }
    }
    printf("404");
    return 0;
}
/*
#include <bits/stdc++.h>
int isPrime(int x) {
    if (x <= 1) return 0;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return 0;
    return 1;
}
int main() {
    int l, k;
    char number[1010], temp[15];
    scanf("%d%d%s", &l, &k, number);
    for (int i = 0; i < l - k + 1; i++) {
        strncpy(temp, number + i, k);
        if (isPrime(atoi(temp))) {
            temp[k] = '\0';
            printf("%s", temp);
            return 0;
        }
    }
    printf("404");
    return 0;
}
*/