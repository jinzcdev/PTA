// https://pintia.cn/problem-sets/994805342720868352/exam/problems/1071785055080476672
#include <bits/stdc++.h>
using namespace std;
bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    bool flag = false;
    for (int i = 0; i <= (int)s.size() - k; i++) {
        if (isprime(stoi(s.substr(i, k)))) {
            cout << s.substr(i, k);
            flag = true;
            break;
        }
    }
    if (!flag) cout << "404";
    return 0;
}
/*
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
    static int l;
    static int k;
    static String n;

    static boolean isPrime(int n) {
        if (n <= 1) {
            return false;
        }

        int sqr = (int) Math.sqrt(n);

        for (int i = 2; i <= sqr; i++) {
            if ((n % i) == 0) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String kl = in.readLine();
        l = Integer.parseInt(kl.split(" ")[0]);
        k = Integer.parseInt(kl.split(" ")[1]);
        n = in.readLine();
        in.close();

        int len = n.length();
        boolean flag = false;

        for (int i = 0; i <= (len - k); i++) {
            String s_num = n.substring(i, i + k);
            int num = Integer.parseInt(n.substring(i, i + k));

            if (isPrime(num)) {
                System.out.println(s_num);
                flag = true;

                break;
            }
        }

        if (!flag) {
            System.out.println("404");
        }
    }
}
*/