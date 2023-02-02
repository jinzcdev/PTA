// https://pintia.cn/problem-sets/14/exam/problems/811
#include <iostream>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int len;
    cin >> len;
    len = len % s.length();
    cout << s.substr(len);
    cout << s.substr(0, len);
    return 0;
}