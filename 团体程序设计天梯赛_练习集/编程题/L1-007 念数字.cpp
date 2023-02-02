// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805136889593856
#include <bits/stdc++.h>
using namespace std;
int main() {
    string number, change[] = {"ling", "yi",  "er", "san", "si",
                               "wu",   "liu", "qi", "ba",  "jiu"};
    cin >> number;
    if (number[0] == '-') {
        cout << "fu ";
        number = number.substr(1);
    }
    for (int i = 0; i < number.size(); i++) {
        if (i != 0) cout << " ";
        cout << change[number[i] - '0'];
    }
    return 0;
}