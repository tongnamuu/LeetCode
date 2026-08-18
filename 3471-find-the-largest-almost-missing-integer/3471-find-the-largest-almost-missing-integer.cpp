class Solution {
public:
    int cnt[51];
    int total[51];
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<k;i++) {
            cnt[nums[i]]++;
        }
        for(int j=0;j<=50;j++) {
            if(cnt[j]) {
                total[j]++;
            }
        }

        for(int i=k;i<n;i++) {
            cnt[nums[i-k]]--;
            cnt[nums[i]]++;
            for(int j=0;j<=50;j++) {
                if(cnt[j]) {
                    total[j]++;
                }
            }
        }
        for(int j=50;j>=0;j--) {
            if(total[j]==1) {
                return j;
            }
        }

        return -1;
    }
};