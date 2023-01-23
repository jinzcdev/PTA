// https://pintia.cn/problem-sets/16/problems/700
typedef struct StackRecord *Stack;
struct StackRecord {
    double Array[Max_Expr];
    int Top;
};
Stack CreateStack() {
    Stack S = (Stack)malloc(sizeof(struct StackRecord));
    S->Top = -1;
    return S;
}
double compute(double a, double b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
    else return a / b;
}
ElementType EvalPostfix(char *expr) {
    Stack S = CreateStack();
    int len = 0, left = 0, right;
    while (expr[len] != '\0') len++;
    for (int i = 0; i < len; i++) {
        if (expr[i] == ' ' || i == len - 1) {
            right = (i == len - 1) ? i : i - 1;
            char tmp[Max_Expr];
            int cnt = 0;
            for (int j = left; j <= right; j++) tmp[cnt++] = expr[j];
            tmp[cnt] = '\0';
            if (tmp[cnt - 1] >= '0' && tmp[cnt - 1] <= '9') {
                S->Array[++S->Top] = atof(tmp);
            } else {
                if (S->Top < 1) return Infinity;
                double b = S->Array[S->Top--];
                double a = S->Array[S->Top--];
                if (tmp[0] == '/' && b == 0) return Infinity;
                S->Array[++S->Top] = compute(a, b, tmp[0]);
            }
            left = i + 1;
        }
    }
    if (S->Top != 0) return Infinity;
    return S->Array[S->Top];
}