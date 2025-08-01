class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        vector<int>temp(1);
        temp[0] = 1;
        ans[0] = temp;
        if(numRows == 1) return ans;
        vector<int>temp2(2);
        temp2[0] = 1;
        temp2[1] = 1;
        ans[1] = temp2;
        if(numRows == 2) return ans;
        for(int i=2;i<numRows;i++) {
            vector<int>& x = ans[i-1];
            vector<int>temp(i+1);
            for(int j=0;j<=i;j++) {
                int left = j -1 >= 0 ? x[j-1] : 0;
                int right = j == i ? 0 : x[j];
                temp[j] = left + right;
            }
            ans[i] = temp;
        }
        return ans;
    }
};