class Solution {
public:
    int findLHS(vector<int>& nums) {
       map<int,int>cnt;
       for(int i : nums) {
          cnt[i]++;
       }
       int ans = 0;
       for(int i : nums) {
        int cur = cnt[i];
        int t = cnt[i+1];
        if(t!=0) {
          ans = max(cur+t, ans);
        }
       }
       return ans;
    }
};