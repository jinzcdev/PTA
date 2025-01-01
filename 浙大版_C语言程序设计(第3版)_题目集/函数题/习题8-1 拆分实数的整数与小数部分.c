// https://pintia.cn/problem-sets/12/exam/problems/type/6?problemSetProblemId=334
void splitfloat( float x, int *intpart, float *fracpart ) {
  *intpart = (int) x;
  *fracpart = x - *intpart;
}