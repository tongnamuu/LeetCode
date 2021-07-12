class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mapper;
        map<char, char> reverse;
        int n = s.length();
        for(int i=0;i<n;++i) {
            char from = s[i];
            char to = t[i];
            auto x = mapper.find(from);
            auto y = reverse.find(to);
            if(x==mapper.end() && y == reverse.end()) {
                mapper[from] = to;
                reverse[to] = from;
            } else if(x!=mapper.end() && y != reverse.end()) {
                if(x->second != to || y->second != from) return false;
            } else return false;
        }
        return true;
    }
};
