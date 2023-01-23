// https://pintia.cn/problem-sets/15/problems/827
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a;
    vector<string> v;
    stack<string> s;
    map<string, int> m_pri{{"(", 0}, {"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}};
    cin >> a;
    int pre = 0, cnt = 0;
    for (int i = 0; i < a.length(); i++) {
        if (!isdigit(a[i]) && a[i] != '.') {
            if ((a[i] != '-' && a[i] != '+') || (i != 0 && (isdigit(a[i - 1]) || a[i - 1] == ')'))) {
                if (i != pre) v.push_back(a.substr(pre, i - pre));
                v.push_back(a.substr(i, 1));
                pre = i + 1;
            }
        }
    }
    if (pre != a.length()) v.push_back(a.substr(pre, a.length() - pre));
    for (auto it : v) {
        if (isdigit(*it.rbegin())) {
            if (cnt++ > 0) cout << " ";
            if (it[0] == '+') it.erase(it.begin());
            cout << it;
        } else if (it == "(") s.push(it);
        else if (it == ")") {
            while (!s.empty() && s.top() != "(") {
                if (cnt++ > 0) cout << " ";
                cout << s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && m_pri[s.top()] >= m_pri[it]) {
                if (cnt++ > 0) cout << " ";
                cout << s.top();
                s.pop();
            }
            s.push(it);
        }
    }
    while (!s.empty()) {
        if (cnt++ > 0) cout << " ";
        cout << s.top();
        s.pop();
    }
    return 0;
}


/*
#include <iostream>
#include <map>
#include <string>
#include <stack>
using namespace std;
string input, tmp;
map<char, int>opera = { {'(',0},{')',0},{'+',1},{'-',1},{'*',2},{'/',2} };
vector<string>output;
stack<char>st;
int main() {
    cin >> input;
    for (int i = 0; i < input.size(); ++i) 
        if ((input[i] == '+' || input[i] == '-') && (i == 0 || input[i - 1] == '(')||isdigit(input[i])) {
            tmp = (input[i] == '+' ? "" : string{ input[i] });
            while (i + 1 < input.size() && !opera.count(input[i + 1]))
                tmp += input[++i];
            output.push_back(tmp);
        }
        else if (input[i] == '(')
            st.push('(');
        else if (input[i] == ')') {
            while (st.top() != '(') {
                output.push_back({ st.top() });
                st.pop();
            }
            st.pop();
        }
        else {
            while (st.size() && opera[input[i]] <= opera[st.top()]) {
                output.push_back({ st.top() });
                st.pop();
            }
            st.push(input[i]);
        }
    while (st.size()) {
        output.push_back({ st.top() });
        st.pop();
    }
    for (int i = 0; i < output.size(); ++i)
        cout << (i ? " " : "") << output[i];
    return 0;
}
*/
