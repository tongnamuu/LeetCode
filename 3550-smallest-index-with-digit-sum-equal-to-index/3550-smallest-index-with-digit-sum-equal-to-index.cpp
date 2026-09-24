class Solution {
public:
    int x(int n) {
        int ans = 0;
        while(n) {
            ans += n%10;
            n/=10;
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            if(i==x(nums[i])) {
                return i;
            }
        }
        return -1;
    }
};