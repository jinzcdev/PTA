// https://pintia.cn/problem-sets/12/problems/308
void StringCount( char s[] ) {
  int letter = 0, blank = 0, digit = 0, other = 0, len = strlen(s);
  for (int i = 0; i < len; i++) {
    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) letter++;
    else if (s[i] >= '0' && s[i] <= '9') digit++;
    else if (s[i] == ' ' || s[i] == '\n') blank++;
    else other++;
  }
  printf("letter = %d, blank = %d, digit = %d, other = %d", letter, blank, digit, other);
}