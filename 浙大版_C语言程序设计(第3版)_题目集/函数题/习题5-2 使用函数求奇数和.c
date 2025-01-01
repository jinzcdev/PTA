// https://pintia.cn/problem-sets/12/exam/problems/type/6?problemSetProblemId=302
int even(int n) { return n % 2 == 0 ? 1 : 0; }
int OddSum(int List[], int N) {
    if (N == 1) {
        if (even(List[0])) return 0;
        return List[0];
    }
    return even(List[N - 1]) ? OddSum(List, N - 1) : OddSum(List, N - 1) + List[N - 1];
}