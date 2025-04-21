class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long s = -100000;
        long long e = 100000;
        int n = differences.size();
        int ans = 0;
        int minValue = 0;
        int maxValue = 0;
        //xxxxxoooooo
        while(s<=e) {
            long long m = (s+e) / 2;
            if(lower_good(m, lower, differences)) {
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        minValue = s;
        // ooooooxxxxx
        s = -100000;
        e = 100000;
        while(s<=e) {
            long long m = (s+e) / 2;
            if(upper_good(m, upper, differences)) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        maxValue = e;
        return max(0, maxValue - minValue + 1);
    }
    bool lower_good(long long val, int target, vector<int>& differences) {
        int n = differences.size();
        for(int i=0;i<n;i++) {
            if(val<target) return false;
            val = differences[i] + val;
        }
        return val >= target;
    }
     bool upper_good(long long val, int target, vector<int>& differences) {
        int n = differences.size();
        for(int i=0;i<n;i++) {
            if(val>target) return false;
            val = differences[i] + val;
        }
        return val <= target;
    }
};