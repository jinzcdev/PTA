// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1621699285882593280
#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, int> months = {{"Jan", 1},  {"Feb", 2},  {"Mar", 3},
                               {"Apr", 4},  {"May", 5},  {"Jun", 6},
                               {"Jul", 7},  {"Aug", 8},  {"Sep", 9},
                               {"Oct", 10}, {"Nov", 11}, {"Dec", 12}};
    int n, dd, yy;
    string mm, date;
    cin >> n;
    while (n--) {
        cin >> mm;
        scanf("%d, %d", &dd, &yy);
        date = to_string(yy * 10000 + months[mm] * 100 + dd);
        while (date.size() != 8) date.insert(date.begin(), '0');
        bool flag = true;
        for (int i = 0; i < date.size() / 2; i++) {
            if (date[i] != date[date.size() - i - 1]) {
                flag = false;
                break;
            }
        }
        printf("%s %s\n", flag ? "Y" : "N", date.c_str());
    }
    return 0;
}