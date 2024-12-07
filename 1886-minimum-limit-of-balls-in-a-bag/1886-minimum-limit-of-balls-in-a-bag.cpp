class Solution {
public:
    bool canDivide(vector<int>& nums, int maxBalls, int maxOperations) {
        int operation = 0;
        for (int n : nums) {
            operation += (n + maxBalls - 1) / maxBalls - 1;
            if (operation > maxOperations) return false;
        }
        return true;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int ans = right;
        
        while (left < right) {
            int mid = (right + left) / 2;
            if (canDivide(nums, mid, maxOperations)) {
                right = mid;
                ans = right;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};