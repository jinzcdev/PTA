// https://pintia.cn/problem-sets/12/problems/334
void splitfloat( float x, int *intpart, float *fracpart ) {
  *intpart = (int) x;
  *fracpart = x - *intpart;
}