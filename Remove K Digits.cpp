class Solution {
   public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if (n == k) return "0";
        stack<char> s;
        int idx = 0;

        while (k && idx < n) {
            while (k && idx < n && !s.empty() && s.top() > num[idx]) {
                s.pop();
                k--;
            }
            s.push(num[idx]);
            idx++;
        }

        while (k > 0) s.pop(), k--;
        for (int i = idx; i < n; ++i) s.push(num[i]);
        string ans = "";
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        int len = ans.length();
        int zero = 0;
        for (zero = 0; zero < len; ++zero)
            if (ans[zero] != '0') break;
        ans = ans.substr(zero);
        if (!ans.length()) return "0";
        return ans;
    }
};