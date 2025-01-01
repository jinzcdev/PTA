// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805110318678016
#include <bits/stdc++.h>
using namespace std;
int convert(string a) {
    if (a[0] == '-') return -1;
    bool flag = true;
    for (int i = 0; i < a.length(); i++) {
        if (!isdigit(a[i])) {
            flag = false;
            break;
        }
    }
    if (!flag || stoi(a) == 0) return -1;
    return stoi(a) <= 1000 ? stoi(a) : -1;
}
int main() {
    string a, b;
    cin >> a;
    getline(cin, b);
    b.erase(b.begin());
    int ta = convert(a), tb = convert(b);
    if (ta != -1 && tb != -1) printf("%d + %d = %d\n", ta, tb, ta + tb);
    else if (ta != -1 && tb == -1) printf("%d + ? = ?\n", ta);
    else if (ta == -1 && tb != -1) printf("? + %d = ?\n", tb);
    else printf("? + ? = ?\n");
    return 0;
}