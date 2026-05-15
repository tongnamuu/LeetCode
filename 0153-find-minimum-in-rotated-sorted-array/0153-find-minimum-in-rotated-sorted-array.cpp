class Solution {
public:
int findIdx(vector<int>& a) {
        int n = a.size();
        if(n==1) return 0;
        int s = 0;
        int e = a.size() - 1;
        if(a[0] < a[e]) return 0;
        while(s<=e) {
            int m = s + e >> 1;
            if(m + 1 < n && a[m] > a[m + 1]) {
                return m + 1;
            }
            if( m - 1 >= 0 && a[m - 1] > a[m]) {
                return m;
            }
            if(a[m] > a[0]) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return -1;
    }
    int findMin(vector<int>& nums) {
        int idx = findIdx(nums);
        return nums[idx];    
    }
};