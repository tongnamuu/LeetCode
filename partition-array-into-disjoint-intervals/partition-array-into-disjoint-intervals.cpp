class Solution {
public:

    int partitionDisjoint(vector<int>& nums) {
        int maxV = nums[0];
        int partition = nums[0];
        int idx = 0;
        for(int i=1;i<nums.size();++i) {
            maxV = max(maxV, nums[i]);
            if(nums[i] < partition) {
                partition = maxV;
                idx = i;
            }
        }
        return idx + 1;
    }
};
