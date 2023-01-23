// https://pintia.cn/problem-sets/994805260223102976/problems/994805293282607104
// #include <iostream>
// using namespace std;
// int main() {
//     int n, cnt = 0;
//     scanf("%d", &n);
//     string name, minName, maxName, birth, minBirth = "9999/99/99", maxBirth = "0000/00/00";
//     while (n--) {
//         cin >> name >> birth;
//         if (birth >= "1814/09/06" && birth <= "2014/09/06") {
//             cnt++;
//             if (birth <= minBirth) {
//                 minBirth = birth;
//                 minName = name;
//             }
//             if (birth >= maxBirth) {
//                 maxBirth = birth;
//                 maxName = name;
//             }
//         }
//     }
//     if (cnt == 0) printf("0");
//     else cout << cnt << " " << minName << " " << maxName << endl;
//     return 0;   
// }

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, yy, mm, dd, cnt = 0, MIN = 99999999, MAX = -1;
    string a, b, s;
    scanf("%d", &n);
    while (n--) {
        cin >> s;
        scanf("%d/%d/%d", &yy, &mm, &dd);
        int temp = yy * 10000 + mm * 100 + dd;
        if (temp >= 18140906 && temp <= 20140906) {
            cnt++;
            if (temp < MIN) {
                MIN = temp;
                a = s;
            }
            if (temp > MAX) {
                MAX = temp;
                b = s;
            }
        }
    }
    if (cnt == 0) printf("0");
    else printf("%d %s %s", cnt, a.c_str(), b.c_str());
    return 0;
}