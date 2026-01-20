class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(int i : nums) {
            int temp = -1;
            for(int j=1;j<=i;j++) {
                int val = (j|(j+1));
                if (val == i) {
                    temp = j;
                    break;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};