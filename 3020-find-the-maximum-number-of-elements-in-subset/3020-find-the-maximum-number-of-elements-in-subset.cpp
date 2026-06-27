class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long, int> cnt;
        int ones = 0;
        for(int i: nums) {
            if(i==1) {
                ones++;
            } else {
                cnt[i]++;
            }
        }

        int ans = (ones % 2 == 1) ? ones : ones - 1;
        ans = max(ans, 1);
        for(int i : nums) {
            if(i==1) continue;
            long long j = i;
            int temp = 0;
            while(true) {
                if (cnt[j] == 1) {
                    temp++;
                    ans = max(ans, temp);
                    break;
                }  else if(cnt[j] >= 2) {
                    ans = max(ans, temp+1);
                    temp+=2;
                } else {
                    break;
                }
                j *= j;
            }
        }
        return ans;
    }
};