// https://pintia.cn/problem-sets/14/problems/809
#include <iostream>
using namespace std;
int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int pos, len = s2.length();
    while ((pos = s1.find(s2)) != string::npos) s1.erase(pos, len);
    cout << s1;
    return 0;
}