// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805270914383872
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main() {
    string str;
    int sum = 0, cntZero = 0, cntOne = 0;
    vector<int> ans;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++) {
        if (isupper(str[i])) sum += str[i] - 'A' + 1;
        else if (islower(str[i])) sum += str[i] - 'a' + 1;
    }
    while (sum != 0) {
        ans.push_back(sum % 2);
        sum /= 2;
    }
    
    for (auto it : ans) {
        if (it == 0) cntZero++;
        else cntOne++;
    }
    printf("%d %d", cntZero, cntOne);
    return 0;
}