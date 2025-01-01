// https://pintia.cn/problem-sets/12/exam/problems/type/6?problemSetProblemId=348
struct complex multiply(struct complex x, struct complex y) {
    struct complex ans;
    ans.real = x.real * y.real - x.imag * y.imag;
    ans.imag = x.imag * y.real + y.imag * x.real;
    return ans;
}