// https://pintia.cn/problem-sets/13/problems/554
bool palindrome( char *s ) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] != s[len - i - 1]) {
            return false;
        }
    }
    return true;
}