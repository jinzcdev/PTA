// https://pintia.cn/problem-sets/12/problems/359
char month[][15] = {"January",   "February", "March",    "April",
                    "May",       "June",     "July",     "August",
                    "September", "October",  "November", "December"};
char *getmonth(int n) {
    if (n <= 0 || n > 12) return NULL;
    return month[n - 1];
}