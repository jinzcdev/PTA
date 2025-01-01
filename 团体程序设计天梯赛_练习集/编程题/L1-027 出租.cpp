// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805107638517760
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
    string a;
    cin >> a;
    set<int> s;
    for (int i = 0; i < a.length(); i++) {
        s.insert(a[i] - '0');
    }
    vector<int> arr, index(a.length());
    for (auto it : s) arr.push_back(it);
    reverse(arr.begin(), arr.end());
    int pos[10] = {0};
    printf("int[] arr = new int[]{");
    for (int i = 0; i < arr.size(); i++) {
        pos[arr[i]] = i;
        if (i != 0) printf(",");
        printf("%d", arr[i]);
    }
    printf("};\nint[] index = new int[]{");
    for (int i = 0; i < a.length(); i++) {
        if (i != 0) printf(",");
        printf("%d", pos[a[i] - '0']);
    }
    printf("};\n");
    return 0;
}