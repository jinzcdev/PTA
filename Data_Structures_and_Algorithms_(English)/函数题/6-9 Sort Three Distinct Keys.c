// https://pintia.cn/problem-sets/16/exam/problems/704
void MySort(ElementType A[], int N) {
    int cntMaybe = 0, pos = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == false) A[pos++] = false;
        else if (A[i] == maybe) cntMaybe++;
    }
    while (cntMaybe--) A[pos++] = maybe;
    while (pos < N) A[pos++] = true;
}