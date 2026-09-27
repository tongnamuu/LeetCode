class Solution {
public:
    string reverseStack(const string& s, const stack<pair<string, int>>& x) {
        return "";
    }
    string reverseParentheses(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == ')') {
                string temp;
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                for (char ch : temp) {
                    st.push(ch);
                }
            } else {
                st.push(c);
            }
        }

        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};