class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>d(n,-1);
        d[0]=1;
        for(int i=1;i<n;++i){
            for(int j=i-1;j>=0;--j){
                if(d[j]!=-1&&i<=j+nums[j]){
                    d[i]=1;
                    break;
                }
            }
        }
        return d[n-1]!=-1;
    }
};
