// https://pintia.cn/problem-sets/14/problems/737
ElementType Max( ElementType S[], int N ) {
    ElementType ans = S[0];
    int i = 0;
    for ( ; i < N; i++) {
        if (S[i] > ans) {
            ans = S[i];
        }
    }
    return ans;
}