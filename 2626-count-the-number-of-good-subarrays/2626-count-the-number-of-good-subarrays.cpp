class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n = nums.size();
        map<int, long long> seen;
        long long ans = 0;
        long long count = 0;
        while(j<n) {
            if(count<k) {
               long long temp = seen[nums[j]];
               count += temp;
               seen[nums[j]]++;
               j++;
            } else {
                while(i<n && count>=k) {
                    ans += (long long)(n-j + 1);
                    cout<<i<<' '<<j<<'\n';
                    seen[nums[i]]--;
                    count -= seen[nums[i]];
                    i++;
                }
            }
        }
        while(i<n && count>=k) {
                    ans += (long long)(n-j + 1);
                    cout<<i<<' '<<j<<'\n';
                    seen[nums[i]]--;
                    count -= seen[nums[i]];
                    i++;
                }
        cout<<i<<' '<<j<<' '<<count<<' '<<ans<<'\n';
        return ans;
    }
};