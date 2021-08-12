class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        vector<pair<string, int>>temp(strs.size());
        for(int i=0;i<strs.size();++i) {
            string s = strs[i];
            sort(s.begin(), s.end());
            temp[i].first = s; 
            temp[i].second = i;
        }
        sort(temp.begin(), temp.end());
        vector<string>v;
        string prev = temp[0].first;
        for(auto& e:temp) {
            if(prev==e.first) {
                v.push_back(strs[e.second]);
            } else {
                prev = e.first;
                ans.push_back(v);
                v.clear();
                v.push_back(strs[e.second]);
            }
        }
        ans.push_back(v);
        return ans;
    }
};
