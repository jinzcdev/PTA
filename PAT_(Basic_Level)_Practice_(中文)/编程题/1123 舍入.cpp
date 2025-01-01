// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1729419194675666946
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, d;
    cin >> n >> d;
    string zeroPadding(200, '0');  // 用于补齐小数位数
    while (n--) {
        int method, pointIdx = 0, carry = 0, isNeg = 0, hasNonZero = 0;
        string number;
        cin >> method >> number;
        if (number[0] == '-') {
            isNeg = 1;
            number.erase(0, 1);
        }
        // 找到小数点位置
        while (pointIdx < number.size() && number[pointIdx] != '.') ++pointIdx;
        if (pointIdx == number.size()) number += '.';
        number += zeroPadding;
        if (method != 2) {
            if (method == 1) {
                number[pointIdx + d + 1] += 5;  // 四舍五入
            } else {
                // 四舍六入五成双
                if (number[pointIdx + d + 1] >= '6') {
                    number[pointIdx + d]++;
                } else if (number[pointIdx + d + 1] == '5') {
                    bool flag = false;
                    for (int i = pointIdx + d + 2; i < number.size(); i++) {
                        if (number[i] != '0') {
                            number[pointIdx + d]++;
                            flag = true;
                            break;
                        }
                    }
                    if (!flag && (number[pointIdx + d] - '0') % 2 != 0) {
                        number[pointIdx + d]++;
                    }
                }
            }
            // 处理进位
            for (int i = pointIdx + d + 1; i >= 0; i--) {
                if (number[i] == '.') continue;
                int currentDigit = number[i] - '0' + carry;
                number[i] = '0' + currentDigit % 10;
                carry = currentDigit / 10;
            }
        }
        // 处理最高位进位
        if (carry) {
            number = '1' + number;
            pointIdx++;
        }
        // 处理负号输出
        if (isNeg) {
            for (int i = 0; i <= pointIdx + d; i++) {
                if (number[i] != '0' && number[i] != '.') {
                    hasNonZero = 1;
                    break;
                }
            }
        }
        if (isNeg && hasNonZero) cout << '-';
        cout << number.substr(0, pointIdx + d + 1) << "\n";
    }
    return 0;
}