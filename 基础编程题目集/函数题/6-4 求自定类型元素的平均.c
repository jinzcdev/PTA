// https://pintia.cn/problem-sets/14/exam/problems/type/6?problemSetProblemId=736
ElementType Average( ElementType S[], int N ) {
    ElementType sum = 0;
    int i = 0;
    for ( ; i < N; i++) {
        sum += S[i];
    }
    return sum / N;
    
}