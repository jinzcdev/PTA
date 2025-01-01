// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805345732378624
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1010;

string reverseNumber(string number) {
    reverse(number.begin(), number.end());
    return number;
}

bool isPld (string str){
    int len = str.size();
    for (int i = 0; i < len; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

string getSum(string number, string rnumber) {
    string sum = number;
    int k = 0, len = number.size(), cnt = 0;
    for (int i = len - 1; i >= 0; i--) {
        int rs = (number[i] - '0') + (rnumber[i] - '0') + k;
        sum[i] = rs % 10 + '0';
        k = rs / 10;
    }
    if (k != 0) sum.insert(sum.begin(), k + '0');
    return sum;
}

int main() {
    string number;
    cin >> number;
    // remove the duplicated zeros.
    string::iterator it = number.begin();
    while (*it == '0') {
        number.erase(it);
        it = number.begin();
    }
    if (isPld(number)) {
        cout << number << " is a palindromic number.\n";
    } else {
        int cnt = 0;
        while (!isPld(number)) {
            if (cnt++ == 10) {
                printf("Not found in 10 iterations.\n");
                break;
            }
            string rnumber = reverseNumber(number);
            cout << number << " + " << rnumber << " = ";
            number =  getSum(number, rnumber);
            cout << number << endl;
        }
        if (cnt < 10) cout << number << " is a palindromic number." << endl;
    }
    return 0;
}

