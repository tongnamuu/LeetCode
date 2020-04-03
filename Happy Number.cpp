class Solution {
   public:
    int cal(int n) {
        int ans = 0;
        while (n) {
            int x = n % 10;
            ans += x * x;
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        map<int, int> check;
        if (n < 0) return false;
        if (n == 1) return true;
        while (n != 1) {
            n = cal(n);
            if (check.find(n) == check.end()) {
                check[n] = 1;
            } else
                return false;
        }
        return true;
    }
};