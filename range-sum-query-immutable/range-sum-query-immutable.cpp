class NumArray {
public:
    vector<int>sums;
    NumArray(vector<int>& nums) {
        sums = vector<int>(nums.size() + 1);
        for(int i=0;i<nums.size();++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return sums[right + 1] - sums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
