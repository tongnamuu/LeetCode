class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        if (n > batteries.size()) {
            return 0L;
        }
        if (n == batteries.size()) {
            return *min_element(batteries.begin(), batteries.end());
        }
        sort(batteries.begin(), batteries.end());
        long long s = 0L;
        long long e = 100000000000000L;
        
        while(s<=e) {
            long long m = (s+e) / 2;
            long long rest = 0L;
            for(int i=0;i<batteries.size();i++) {
                rest += min((long long)batteries[i], m);
            }
            if (n * m <= rest) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return e;
    }
};