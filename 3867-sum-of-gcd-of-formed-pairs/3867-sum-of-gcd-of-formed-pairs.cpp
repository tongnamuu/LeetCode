class Solution {
public:
    int gcd(int x, int y) {
        if(y==0) return x;
        return gcd(y, x%y);
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixGcd(n);
        int mv = nums[0];
        for(int i=0;i<n;i++) {
            mv = max(mv, nums[i]);
            prefixGcd[i] = gcd(nums[i], mv);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int i = 0;
        int j = n - 1;
        long long ans = 0L;
        while(i<j) {
            ans += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }
        return ans;
    }
};