class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int start = 1;
        for(int i=0;i<n-1;i++) {
            start = good(i, start, derived);
        }
        if(start^1 == derived.back()) return true;

        start = 0;
        for(int i=0;i<n-1;i++) {
            start = good(i, start, derived);
        }
        if(start^0 == derived.back()) return true;
        return false;
    }

    int good(int idx, int val, vector<int>& derived) {
        if(val^1 == derived[idx]) return 1;
        else return 0;
    }
};