// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805324509200384
#include <bits/stdc++.h>
using namespace std;
string pinyin[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int cnt = 0;
void readNumber(int x) {
    if (x == 0) return;
    readNumber(x / 10);
    if (cnt++ > 0) cout << " ";
    cout << pinyin[x % 10];
}
int main() {
    string s;
    cin >> s;
    int sum = 0;
    for (auto it : s) sum += it - '0';
    if (sum == 0) cout << "ling";
    else readNumber(sum);
    return 0;
}
/* JAVA
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int sum = 0;
		String s = in.nextLine();
		in.close();
		char[] ch1 = s.toCharArray();
		for (int i = 0; i < ch1.length; i++) {
			sum += (ch1[i] - 48);
		}

		char[] ch2 = (sum + "").toCharArray();
		for (int i = 0; i < ch2.length; i++) {
            String[] str = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
			String s1 = str[ch2[i] - 48];
			System.out.print(s1);
			if (i != ch2.length - 1)
				System.out.print(" ");
		}
	}
}
*/

/* 循环输出
#include <iostream>
#include <vector>
using namespace std;
string change[10] = {"ling", "yi",  "er", "san", "si",
                     "wu",   "liu", "qi", "ba",  "jiu"};
int main() {
    vector<int> ans;
    string s;
    int number = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++) number += s[i] - '0';
    while (number != 0) {
        ans.push_back(number % 10);
        number /= 10;
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        if (i != ans.size() - 1) printf(" ");
        cout << change[ans[i]];
    }
    return 0;
}
*/