// https://pintia.cn/problem-sets/15/problems/3001
#include <bits/stdc++.h>
using namespace std;
int findMedianSortedArrays1(vector<int>& num1, vector<int>& num2) {
    // O(M+N)
    int m = num1.size(), n = num2.size();
    int i = 0, j = 0, ans, cnt = 0;
    while (i < m && j < n && cnt++ < n) {
        if (num1[i] <= num2[j])
            ans = num1[i++];
        else
            ans = num2[j++];
    }
    while (i < n && cnt++ < n) ans = num1[i++];
    while (j < n && cnt++ < n) ans = num2[j++];
    return ans;
}
int findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
	// from: https://leetcode.cn/problems/median-of-two-sorted-arrays
	// O(log min(M, N))
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays2(nums2, nums1);
    }

    int m = nums1.size();
    int n = nums2.size();
    int left = 0, right = m;
    // median1：前一部分的最大值
    // median2：后一部分的最小值
    int median1 = 0, median2 = 0;

    while (left <= right) {
        // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
        // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
        int i = (left + right) / 2;
        int j = (m + n + 1) / 2 - i;

        // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i-1], nums1[i],
        // nums2[j-1], nums2[j]
        int nums_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);
        int nums_i = (i == m ? INT_MAX : nums1[i]);
        int nums_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
        int nums_j = (j == n ? INT_MAX : nums2[j]);

        if (nums_im1 <= nums_j) {
            median1 = max(nums_im1, nums_jm1);
            median2 = min(nums_i, nums_j);
            left = i + 1;
        } else {
            right = i - 1;
        }
    }
	return median1;
    // return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    printf("%d", findMedianSortedArrays1(a, b));
    return 0;
}