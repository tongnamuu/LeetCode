class Solution {
   public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int u, const int v) {
            return to_string(u) + to_string(v) > to_string(v) + to_string(u);
        });
        string ans;
        for (int i : nums) {
            ans += to_string(i);
        }
        if (ans[0] == '0') return "0";
        return ans;
    }
};
