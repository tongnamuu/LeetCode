class Solution {
public:
    int search(vector<int>& nums, int s, int e, int target) {
        while(s<=e) {
            int m = (s+e) / 2;
            if(nums[m]>target) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return s;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        for(int j=0;j<m;j++) {
            int idx = search(nums1, 0, min(j, n-1), nums2[j]);
            if(idx>=0 && idx<=j && idx<n&&nums1[idx]<=nums2[j]) {
                ans = max(ans, j-idx);
                cout<<idx<<' '<<j<<' '<<nums1[idx]<<' '<<nums2[j]<<'\n';
            }
        }
        return ans;
    }
};