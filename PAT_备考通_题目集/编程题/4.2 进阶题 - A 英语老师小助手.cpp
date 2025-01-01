// https://pintia.cn/problem-sets/1526027869896364032/exam/problems/type/7?problemSetProblemId=1526201707548430336
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        bool flag = true;
        for (int i = 0; i < s.size() - 1; i++) {
            if ((isupper(s[i]) && (s[i + 1] != tolower(s[i]) && s[i + 1] != s[i] - 1)) ||
                (islower(s[i]) && (s[i + 1] != toupper(s[i]) && s[i + 1] != s[i] + 1))) {
                flag = false;
                break;
            }
        }
        printf("%s\n", flag ? "Y" : "N");
    }
    return 0;
}
/* python 本题目用python总是会超时
n = int(input())
for _ in range(n):
    s = input()
    flag = True
    for i in range(len(s) - 1):
        if ((s[i].isupper() and (s[i + 1] != s[i].lower() and s[i + 1] != chr(ord(s[i]) - 1)))
                or (s[i].islower() and (s[i + 1] != s[i].upper() and s[i + 1] != chr(ord(s[i]) + 1)))):
            flag = False
            break
    print("Y" if flag else "N")
*/