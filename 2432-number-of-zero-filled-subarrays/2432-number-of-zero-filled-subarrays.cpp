class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
      long long ans = 0L;
      int i = 0;
      int n = nums.size();
      int prev = -1;
      for(int i=0;i<n;i++) {
        if(nums[i]==0) {
            if(prev==-1) {
                prev = i;
            }
        } else {
            if(prev==-1) continue;
            long long cnt = i-1-prev+1;
            ans += (cnt*(cnt+1)/2);
            prev = -1;
        }
      }
      if(prev!=-1) {
        long long cnt = n - 1 - prev + 1;
        ans += cnt*(cnt+1)/2;
      }
      return ans;
    }
};