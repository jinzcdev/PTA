// https://pintia.cn/problem-sets/994805260223102976/problems/994805268334886912
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int n, m;
};
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b, int c) {
    int temp = a * b / gcd(a, b);
    return temp * c / gcd(temp, c);
}
int main() {
    int n1, m1, n2, m2, k;
    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
    if(n1 * m2 > n2 * m1) {
        swap(n1, n2);
        swap(m1, m2);
    }
    int m = lcm(m1, m2, k), left = m / m1 * n1, right = m / m2 * n2;
    int temp = m / k;
    vector<node> ans;
    for (int i = left + 1; i < right; i++) {
        if (i % temp == 0 && gcd(i / temp, k) == 1) {
            ans.push_back({i / temp, k});
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d/%d", ans[i].n, ans[i].m);
    }
    return 0;
}