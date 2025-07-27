class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        bool up = false;
        bool down = false;
        int ans = 0;
        while(i<n) {
            if(nums[i-1] < nums[i]) {
                if(down) {
                    ans++;
                }
                up = true;
                down = false;
            } else if(nums[i-1] > nums[i]) {
                if (up) {
                    ans++;
                }
                up = false;
                down = true;
            } 
            i++;
        }
        return ans;
    }
};