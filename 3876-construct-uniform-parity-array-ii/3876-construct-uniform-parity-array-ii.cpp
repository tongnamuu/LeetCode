class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> odd;
        vector<int>even;
        for(int i: nums1) {
            if(i&1) odd.push_back(i);
            else even.push_back(i);
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        bool ok = true;
        for(int i:nums1) {
            if(i&1) {
                continue;
            } else {
                if(odd.empty() || odd[0] > i) {
                    ok = false;
                    break;
                }

            }
        }
        if(ok) return true;
        ok = true;
        for(int i:nums1) {
            if(i&1) {
                if(odd.empty() || odd[0] >= i) {
                    ok = false;
                    break;
                } 
            } else {
                continue;
            }
        }
        return ok;
    }
};