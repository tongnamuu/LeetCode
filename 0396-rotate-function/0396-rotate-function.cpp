class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        int temp = 0;
        for(int i=0;i<n;i++) {
            total += nums[i];
            temp += (i+1)*nums[i];
        }
        int ans = temp;
        for(int i=0;i<n;i++) {
            temp = temp - total + n*nums[i];
            ans = max(ans, temp);
            cout<<temp - total <<'\n';
        }
        return ans - total;
    }
};