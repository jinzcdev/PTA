// https://pintia.cn/problem-sets/994805342720868352/exam/problems/1478635767601967104
#include <bits/stdc++.h>
using namespace std;
string letter[26][7];
void print(string s) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < s.length(); j++) {
            if (j != 0) printf(" ");
            cout << letter[s[j] - 'A'][i];
        }
        printf("\n");
    }
}
int main() {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> letter[i][j];
        }
    }
    getchar();
    string word;
    getline(cin, word);
    int start = 0;
    vector<string> ans;
    string it = "";
    for (int i = 0; i < word.length(); i++) {
        if (isupper(word[i])) it += word[i];
        if (!isupper(word[i]) || i == word.length() - 1) {
            if (it != "") {
                ans.push_back(it);
                it = "";
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf("\n");
        print(ans[i]);
    }
    return 0;
}