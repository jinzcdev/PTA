// https://pintia.cn/problem-sets/15/problems/836
#include <bits/stdc++.h>
using namespace std;
double pop(stack<double> &s) {
    if (s.empty()) return 0;
    double top = s.top();
    s.pop();
    return top;
}
double compute(double &a, double &b, char op) {
    if (op == '-') return a - b;
    else if (op == '+') return a + b;
    else if (op == '*') return a * b;
    else {
        if (b == 0) {
            printf("ERROR");
            exit(0);
        }
        return a / b;
    }
}
int main() {
    stack<double> s;
    string str;
    vector<string> v;
    double ans = 0;
    while (cin >> str) v.push_back(str);
    for (int i = v.size() - 1; i >= 0; i--) {
        str = move(v[i]);
        if (isdigit(str[str.length() - 1])) {
            s.push(stod(str));
        } else {
            double a = pop(s), b = pop(s);
            s.push(compute(a, b, str[0]));
        }
    }
    printf("%.1f", s.top());
    return 0;
}