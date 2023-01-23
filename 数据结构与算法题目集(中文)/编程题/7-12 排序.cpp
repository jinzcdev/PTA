// https://pintia.cn/problem-sets/15/problems/720
#include <bits/stdc++.h>
using namespace std;
void QuickSort(vector<int> &a, int left, int right) {
    if (left >= right) return;
    int i = left, j = right, key = a[left], flag = 1;
    while (i < j) {
        while (i < j && a[j] >= key) j--;
        a[i] = a[j];
        while (i < j && a[i] <= key) i++;
        a[j] = a[i];
    }
    a[i] = key;
    QuickSort(a, left, i - 1);
    QuickSort(a, i + 1, right);
}
int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    QuickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    return 0;
}