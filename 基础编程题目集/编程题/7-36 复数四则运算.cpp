// https://pintia.cn/problem-sets/14/problems/816
#include <bits/stdc++.h>
using namespace std;
struct node {
    float a, b;
};
node add(node n1, node n2) {
    node ans;
    ans.a = n1.a + n2.a;
    ans.b = n1.b + n2.b;
    return ans;
}
node subtract(node n1, node n2) {
    node ans;
    ans.a = n1.a - n2.a;
    ans.b = n1.b - n2.b;
    return ans;
}
node multiply(node n1, node n2) {
    node ans;
    float a, b;
    a = n1.a * n2.a - n1.b * n2.b;
    b = n1.a * n2.b + n1.b * n2.a;
    ans = {a, b};
    return ans;
}
node divide(node n1, node n2) {
    node ans;
    float a, b, div = n2.a * n2.a + n2.b * n2.b;
    a = n1.a * n2.a + n1.b * n2.b;
    b = n1.b * n2.a - (n1.a * n2.b);
    ans = {a / div, b / div};
    return ans;
}
int main() {
    node n1, n2;
    scanf("%f%f%f%f", &n1.a, &n1.b, &n2.a, &n2.b);
    node (*funs[])(node, node) = {add, subtract, multiply, divide};
    char op[] = "+-*/";
    for (int i = 0; i < 4; i++) {
        node ans = funs[i](n1, n2);
        ans.a = (int)(ans.a * 10 + 0.5 * (ans.a < 0 ? -1 : 1)) / 10.0;
        ans.b = (int)(ans.b * 10 + 0.5 * (ans.b < 0 ? -1 : 1)) / 10.0;
        printf("(%.1f%c%.1fi) %c (%.1f%c%.1fi) = ", n1.a, n1.b >= 0 ? '+' : '-', 
                fabs(n1.b), op[i], n2.a, n2.b >= 0 ? '+' : '-', fabs(n2.b));
        if (ans.a == 0.0 && ans.b == 0.0) printf("0.0\n");
        else if (ans.a == 0.0) printf("%.1fi\n", ans.b);
        else if (ans.b == 0.0) printf("%.1f\n", ans.a);
        else printf("%.1f%c%.1fi\n", ans.a, ans.b >= 0 ? '+' : '-', fabs(ans.b));
    }
    return 0;
}
