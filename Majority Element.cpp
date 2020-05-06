class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int val = 0, cnt = 0;
        for (int& num : nums) {
            if (!cnt) val = num;
            cnt += (val == num) ? 1 : -1;
        }
        return val;
    }
};