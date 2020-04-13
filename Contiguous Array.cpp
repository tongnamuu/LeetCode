class Solution {
   public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> m;
        m[0] = -1;
        int ans = 0, len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            len = len + (nums[i] == 1 ? 1 : -1);
            if (m.find(len) != m.end()) {
                ans = max(ans, i - m[len]);
            } else {
                m[len] = i;
            }
        }
        return ans;
    }
};