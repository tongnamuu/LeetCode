class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1;i++) {
            if(nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        vector<int>temp(n);
        int idx = 0;
        int zero = 0;
        for(int i : nums) {
            if(i==0) {
                zero++;
            } else {
                temp[idx++] = i;
            }
        }
        while(idx<n) {
            temp[idx++] = 0;
        }
        return temp;
    }
};