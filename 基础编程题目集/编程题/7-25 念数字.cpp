// https://pintia.cn/problem-sets/14/exam/problems/type/7?problemSetProblemId=805
#include <iostream>
using namespace std;
int main() {
    char snum[][5] = {"ling", "yi",  "er", "san", "si",
                      "wu",   "liu", "qi", "ba",  "jiu"};
    string number;
    cin >> number;
    if (number[0] == '-') {
        cout << "fu ";
        number = number.substr(1, number.length() - 1);
    }
    for (int i = 0; i < number.length(); i++) {
        if (i != 0) printf(" ");
        cout << snum[number[i] - '0'];
    }
    return 0;
}