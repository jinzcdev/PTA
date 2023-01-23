// https://pintia.cn/problem-sets/1146683407522816000/problems/1192048588307607552
#include <iostream>
using namespace std;
int main() {
    int n;
    string str;
    cin >> n;
    while (n--) {
        cin >> str;
        int a = 0, b = 0;
        for (int i = 0; i < 3; i++) a += (str[i] - '0');
        for (int i = 3; i < 6; i++) b += (str[i] - '0');
        if (a == b) printf("You are lucky!\n");
        else printf("Wish you good luck.\n");
    }
    return 0;
}