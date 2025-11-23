class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<vector<int>>a = vector<vector<int>>(2);
        for(int i : nums) {
            sum += i;
            if(i%3!=0) a[(i%3) - 1].push_back(i);
        }
        if((sum%3)==0) {
            return sum;
        }
        sort(a[0].begin(), a[0].end());
        sort(a[1].begin(), a[1].end());
        if (sum%3 == 1) {
            int temp = 0;
            if (a[0].size() >= 1) {
                temp = max(temp, sum - a[0][0]);
            }
            if(a[1].size()>=2) {
                temp = max(temp, sum - a[1][0] - a[1][1]);
            }
            return temp;
        }
        if (sum%3 == 2) {
            int temp = 0;
            if (a[1].size() >= 1) {
                temp = max(temp, sum - a[1][0]);
            }
            if(a[0].size()>=2) {
                temp = max(temp, sum - a[0][0] - a[0][1]);
            }
            return temp;
        }
        return 0;
    }
};