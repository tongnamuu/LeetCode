class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        vector<int> temp;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
               temp.push_back(nums[i] * nums[j]);
            }
        }
        sort(temp.begin(), temp.end());
        int m = temp.size();
        int prev = temp[0];
        int cnt = 1;
        for(int i=1;i<m;i++) {
            //cout<<temp[i]<<'\n';
            if(prev == temp[i]) {
                cnt++;
            } else {
                //cout<<prev <<' '<<cnt<<'\n';
                ans += cnt * (cnt-1) * 2 * 2;
                cnt = 1;
            }
            prev = temp[i];
        }
        ans += cnt * (cnt-1) * 2 * 2;
        return ans;
    }
};