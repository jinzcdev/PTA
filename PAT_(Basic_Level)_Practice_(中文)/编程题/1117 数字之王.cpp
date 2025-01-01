// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1697150941050929153
#include <bits/stdc++.h>
using namespace std;
int ansMaxCnt = 0;
unordered_map<int, int> cubeSum;
int getCubeSum(int x) {
    if (cubeSum.count(x)) return cubeSum[x];
    return cubeSum[x] = x * x * x;
}
int getAllDigitSum(int x) {
    if (x == 0) return 0;
    int ans = 1;
    while (x != 0) {
        ans *= getCubeSum(x % 10);
        x /= 10;
    }
    x = ans;
    int sum = 0;
    while (x != 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
bool isAllSingleDigit(vector<int> &digits, set<int> &nums) {
    bool flag = true;
    int maxCnt = 0, n = (int)digits.size();
    unordered_map<int, int> digitCount;
    for (int i = 0; i < n; i++) {
        if (digits[i] >= 10) {
            flag = false;
        }
        if (++digitCount[digits[i]] > maxCnt) {
            nums.clear();
            nums.insert(digits[i]);
            maxCnt = digitCount[digits[i]];
        } else if (digitCount[digits[i]] == maxCnt) {
            nums.insert(digits[i]);
        }
        digits[i] = getAllDigitSum(digits[i]);
    }
    if (flag) {
        ansMaxCnt = max(ansMaxCnt, maxCnt); 
    }
    return flag;
}
int main() {
    int a, b;
    cin >> a >> b;
    vector<int> digits;
    for (int x = a; x <= b; x++) {
        digits.push_back(x);
    }
    set<int> nums;
    while (!isAllSingleDigit(digits, nums)) {
        nums.clear();
    }
    cout << ansMaxCnt << endl;
    int cnt = 0;
    for (auto it = nums.begin(); it != nums.end(); it++) {
        if (cnt++ > 0) cout << " ";
        cout << *it;
    }
    return 0;
}