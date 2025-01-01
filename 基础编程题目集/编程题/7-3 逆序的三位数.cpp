// https://pintia.cn/problem-sets/14/exam/problems/type/7?problemSetProblemId=783
#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    int last = s.length() - 1;
    while (s[last] == '0' && last >= 0) last--;
    for (int i = last; i >= 0; i--) printf("%c", s[i]);
    return 0;
}