class Solution {
   public:
    bool v6check(const string& s) {
        int n = s.length();
        if (!n || n > 4) return false;
        for (char c : s) {
            if (c >= '0' && c <= '9')
                continue;
            else if (c >= 'a' && c <= 'f')
                continue;
            else if (c >= 'A' && c <= 'F')
                continue;
            else
                return false;
        }
        return true;
    }
    bool v4check(const string& s) {
        for (char c : s) {
            if (c >= '0' && c <= '9')
                continue;
            else
                return false;
        }
        return true;
    }
    int toNum(const string& s) {
        int ans = 0;
        int n = s.length();
        if (n >= 4 || !n) return 10000;
        if (n > 1 && s[0] == '0') return 10000;
        for (int i = 0; i < n; ++i) {
            ans *= 10;
            ans += s[i] - '0';
        }
        return ans;
    }
    string solvec4(int n, string& s) {
        s += '.';
        int idx = 0, e = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '.') {
                e = i - 1;
                int len = e - idx + 1;
                if (len <= 0) return "Neither";
                string temp = s.substr(idx, len);
                if (!v4check(temp) || toNum(temp) > 255) return "Neither";
                idx = i + 1;
            }
        }
        return "IPv4";
    }
    string solvec6(int n, string& s) {
        s += ':';
        int idx = 0, e = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ':') {
                e = i - 1;
                int len = e - idx + 1;
                if (len <= 0) return "Neither";
                string temp = s.substr(idx, len);
                if (!v6check(temp)) return "Neither";
                idx = i + 1;
            }
        }
        return "IPv6";
    }
    string validIPAddress(string IP) {
        int n = IP.length();
        int c4 = 0, c6 = 0;
        for (int i = 0; i < n; ++i) {
            if (IP[i] == '.') ++c4;
            if (IP[i] == ':') ++c6;
        }
        if (c4 && c6) return "Neither";
        if (c4 == 3)
            return solvec4(n + 1, IP);
        else if (c6 == 7)
            return solvec6(n + 1, IP);
        else
            return "Neither";
    }
};