// https://pintia.cn/problem-sets/14/exam/problems/type/6?problemSetProblemId=735
int Sum ( int List[], int N ){
    int sum = 0;
    for (int i = 0 ; i < N; i++){
        sum += List[i];
    }
    return sum;
}