// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1478634605024231424
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
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 7; j++) cin >> letter[i][j];
    getchar();
    string word;
    getline(cin, word);
    int cnt = 0;
    string it = "";
    for (int i = 0; i < word.length(); i++) {
        if (isupper(word[i])) it += word[i];
        if (!isupper(word[i]) || i == word.length() - 1) {
            if (it != "") {
                if (cnt++ > 0) printf("\n");
                print(it);
                it = "";
            }
        }
    }
    return 0;
}