// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805266007048192
#include <iostream>
using namespace std;
int main() {
    string password, temp;
    int n, cnt = 0;
    cin >> password >> n;
    getchar();
    while(1) {
        getline(cin, temp);
        if (temp == "#") break;
        cnt++;
        if (cnt <= n && temp == password) {
            cout << "Welcome in";
            break;
        } else if (cnt <= n && temp != password) {
            cout << "Wrong password: " << temp << endl;
            if (cnt == n) {
                cout << "Account locked";
                break;
            }
        }
    }
    return 0;
}