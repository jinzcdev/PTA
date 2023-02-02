// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805283241443328
#include <iostream>
using namespace std;
int main() {
    string a, b;
    int cnt = 0, shop[128] = {0}, eva[128] = {0};
    cin >> a >> b;
    for (auto s : a) shop[s]++;
    for (auto s : b)
        if (--shop[s] < 0) cnt++;
    printf("%s %d", cnt > 0 ? "No" : "Yes", cnt > 0 ? cnt : a.length() - b.length());
    return 0;
}