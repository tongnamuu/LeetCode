class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<string, int> m;
        int numbering = 1;
        vector<vector<string>> ans;
        for (int i = 0; i < n; ++i) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            int x = m[temp];
            if (!x) {
                m[temp] = numbering++;
                vector<string> st;
                st.push_back(strs[i]);
                ans.push_back(st);
            } else {
                ans[x - 1].push_back(strs[i]);
            }
        }
        return ans;
    }
};