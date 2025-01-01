// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805262622244864
#include <string>
#include <iostream>
 
using namespace std;
 
int main() {
    string a;
    cin >> a;
    while (cin >> a) {
        if (a[2] == 'T') printf("%d", a[0]-'A'+1);
    }
    return 0;
}