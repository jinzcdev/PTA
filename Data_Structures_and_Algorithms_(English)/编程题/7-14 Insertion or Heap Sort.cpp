// https://pintia.cn/problem-sets/16/exam/problems/676
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n;
void downAdjust(vector<int> &heap, int low, int high) {
    int i = low, j = i * 2;
    while (j <= high) {
        if (j + 1 <= high && heap[j + 1] > heap[j]) j++;
        if (heap[i] >= heap[j]) break;
        swap(heap[i], heap[j]);
        i = j;
        j = i * 2;
    }
}
int main() {
    scanf("%d", &n);
    vector<int> origin(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &origin[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    int pos = 2, j;
    while (pos <= n && v[pos - 1] <= v[pos]) j = ++pos;
    while (pos <= n && v[pos] == origin[pos]) pos++;
    if (pos == n + 1) {
        printf("Insertion Sort\n");
        sort(v.begin() + 1, v.begin() + j + 1);
    } else {
        printf("Heap Sort\n");
        pos = n;
        vector<int> temp(v);
        sort(temp.begin(), temp.end());
        while (pos >= 1 && v[pos] == temp[pos]) pos--;
        swap(v[1], v[pos]);
        downAdjust(v, 1, pos - 1);
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) printf(" ");
        printf("%d", v[i]);
    }
    return 0;
}