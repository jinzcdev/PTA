#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[3], b[3];
    string arr[] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                    "Thursday", "Friday", "Saturday"};
    string days[] = {"yesterday", "today", "tomorrow"};
    for (int i = 0; i < 3; i++) scanf("%d", a + i);
    for (int i = 0; i < 3; i++) scanf("%d", b + i);
    a[0] = (a[0] + 1) % 7;
    a[2] = (a[2] - 1 + 7) % 7;
    b[0] = (b[0] + 1) % 7;
    b[2] = (b[2] - 1 + 7) % 7;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i] == b[j]) {
                cout << arr[a[i]] << endl;
                cout << days[i] << endl;
                cout << days[j] << endl;
                return 0;
            }
        }
    }
    return 0;
}