// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805466364755968
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int n, k = 2, temp;
    vector<long int> nums1, nums2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        nums1.push_back(temp);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        nums2.push_back(temp);
    }
    int len = (nums1.size() + nums2.size() + 1) / 2, i = 0, j = 0, cnt = 0;
    long int ans;
    while (cnt < len) {
        if (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) ans = nums1[i++];
            else ans = nums2[j++];
        } 
        else if (i >= nums1.size()) ans = nums2[j++];
        else if (j >= nums2.size()) ans = nums1[i++];
        cnt++;
    }
    printf("%ld", ans);
    return 0;
}