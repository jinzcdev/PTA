// https://pintia.cn/problem-sets/14/exam/problems/741
int Count_Digit ( const int N, const int D ) {
    if (N < 0) return Count_Digit(-N, D);
    if (N < 10) return N == D ? 1 : 0;
    return (N % 10 == D) + Count_Digit(N / 10, D);
}

// int Count_Digit ( const int N, const int D ) {
//     if (N == 0 && D == 0) return 1;
//     int temp = N > 0 ? N : -N, cnt = 0;
//     while (temp != 0) {
//         if (temp % 10 == D) cnt++;
//         temp /= 10;
//     }
//     return cnt;
// }