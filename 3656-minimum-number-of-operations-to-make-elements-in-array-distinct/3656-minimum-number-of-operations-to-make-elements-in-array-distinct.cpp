class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        for(int i=0,j=0;;i+=3,j+=1) {
            if(good(nums, i)) {
                return j;
            }
        }
    }

    bool good(vector<int>& nums, int idx) {
        set<int> st;
        for(int i=idx;i<nums.size();i++) {
            if(st.find(nums[i]) != st.end()) return false;
            st.insert(nums[i]);
        }
        return true;
    }
};