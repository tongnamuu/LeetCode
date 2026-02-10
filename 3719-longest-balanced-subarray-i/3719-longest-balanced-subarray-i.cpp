class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        map<int, int> odd;
        map<int, int> even;
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                if((nums[j]%2)==0) {
                    even[nums[j]]++;
                } else {
                    odd[nums[j]]++;
                }
                if (even.size()==odd.size()) {
                    ans = max(ans, (j-i+1));
                }
            }
            for(int j=i;j<n;j++) {
                if((nums[j]%2)==0) {
                    even[nums[j]]--;
                    if(even[nums[j]]==0) even.erase(nums[j]);
                } else {
                    odd[nums[j]]--;
                    if(odd[nums[j]]==0) odd.erase(nums[j]);
                }
            }
        }
        return ans;
    }
};