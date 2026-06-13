class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(string& s : words) {
            int idx = 0;
            for(char c: s){
                idx += weights[c-'a'];
                idx %= 26; 
            }
            idx = 25-idx;
            ans+=('a'+idx);
        }
        return ans;
    }
};