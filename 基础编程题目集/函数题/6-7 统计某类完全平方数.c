// https://pintia.cn/problem-sets/14/exam/problems/type/6?problemSetProblemId=739
int IsTheNumber ( const int N ) {
    int hash[10] = {0}, temp = N, i;
    while (temp != 0) {
        hash[temp % 10]++;
        temp /= 10;
    }
    int flag = 0;
    for (i = 0; i <= 9; i++) {
        if (hash[i] >= 2) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) return 0;
    int sqr = (int)sqrt(N);
    if (pow(sqr, 2) == N) return 1;
    else return 0;
}