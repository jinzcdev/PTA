// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805279328157696
#include <iostream>
#include <map>
#include <cctype>
using namespace std;
string l[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string h[13] = {"#", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> mp;
int main() {
    for (int i = 0; i < 13; i++) {
        mp[l[i]] = i;
        mp[h[i]] = i * 13;
    }
    int n;
    cin >> n;
    getchar();
    string d;
    while (n--) {
        getline(cin, d);
        if (isdigit(d[0])) {
            int temp = stoi(d);
            if (temp < 13) cout << l[temp] << endl;
            else if (temp % 13 == 0) cout << h[temp / 13] << endl;
            else cout << h[temp / 13] << " " << l[temp % 13] << endl;
        } else {
            if (d.find(' ') != string::npos) {
                int spos = (int) d.find(' ');
                cout << mp[d.substr(0, spos)] + mp[d.substr(spos + 1)] << endl;
            } else {
                cout << mp[d] << endl;
            }
        }
    }
    return 0;
}