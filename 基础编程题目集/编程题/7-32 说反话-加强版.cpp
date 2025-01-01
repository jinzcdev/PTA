// https://pintia.cn/problem-sets/14/exam/problems/type/7?problemSetProblemId=812
#include <iostream>
#include <vector>
using namespace std;
int main() {
    string word;
    vector<string> ans;
    while (cin >> word) {
        ans.push_back(word);
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        if (i != ans.size() - 1) printf(" ");
        cout << ans[i];
    }
    return 0;
}