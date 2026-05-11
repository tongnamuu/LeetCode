class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i:nums) {
            bool begin = false;
            for(int j=1000000;j>=1;j/=10) {
                int x = i/j;
                i -= x*j;
                if(x) {
                    begin = true;
                }
                if(begin) {
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }
};