class Solution {
public:
    pair<int, int> get(const string& s) {
        int value = 0;
        int qcount = 0;
        for(char c : s) {
            if(c=='?') qcount++;
            else value += (c-'0');
        }
        return {value, qcount};
    }
    bool sumGame(string num) {
        int n = num.size();
        pair<int, int> x1 = get(num.substr(0, n/2));
        pair<int, int> x2 = get(num.substr(n/2, n/2));
        if((x1.second + x2.second)%2 == 1) {
            return true;
        }
        if(x1.first - x2.first != (x2.second - x1.second)*9 / 2) {
            return true;
        }
        return false;
    }
};