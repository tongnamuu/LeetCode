class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> x;
        int n = nums.size();
        for(int i : nums) x.insert(i);
        int temp = x.size();
        
        int i=0;
        int j=0;
        map<int, int> m;
        m[nums[j]] = 1;
        int ans = 0;
        while(i<n&&j<n) {
            if(m.size()==temp) {
                ans+= n - 1 - j + 1;

                m[nums[i]]--;
                if(m[nums[i]]==0) {
                    m.erase(nums[i]);
                }
                i++;

            } else if (m.size() < temp) {
                j++;
                if(j<n) {
                    m[nums[j]]++;
                }

            }
        }
        return ans;
    }
};