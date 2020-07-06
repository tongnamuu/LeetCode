class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n = digits.size();
        int prev = digits[n - 1] + 1;
        ans.push_back(prev % 10);
        for (int i = n - 2; i >= 0; --i) {
            if (prev == 10) {
                digits[i]++;
                prev = digits[i];
                ans.push_back(prev % 10);
            } else {
                ans.push_back(digits[i]);
                prev = digits[i];
            }
        }
        if (prev == 10) ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};