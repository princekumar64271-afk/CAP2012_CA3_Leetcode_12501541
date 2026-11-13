#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for (const string& token : tokens) {
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {
                long long right = st.top(); st.pop();
                long long left = st.top(); st.pop();
                if (token == "+") st.push(left + right);
                else if (token == "-") st.push(left - right);
                else if (token == "*") st.push(left * right);
                else st.push(left / right);
            } else {
                st.push(stoll(token));
            }
        }
        return (int)st.top();
    }
};
