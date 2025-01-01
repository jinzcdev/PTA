// https://pintia.cn/problem-sets/13/exam/problems/type/6?problemSetProblemId=461
int even( int n ) {
    return n % 2 ? 0 : 1;
}
int OddSum( int List[], int N ) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (even(List[i]) == 0) {
            sum += List[i];
        }
    }
    return sum;
}