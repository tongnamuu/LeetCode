class Solution {
   public:
    int singleNonDuplicate(vector<int>& a) {
        if (a.size() == 1) return a[0];
        int s = 0, e = a.size() - 1;
        while (s <= e) {
            int m = s + e >> 1;
            if (m == 0) {
                if (a[m] != a[m + 1]) return a[m];
                s = m + 2;
            } else if (m == a.size() - 1) {
                if (a[m - 1] != a[m]) return a[m];
                e = m - 2;
            } else {
                if (a[m] == a[m - 1]) {
                    if ((m - s + 1) & 1)
                        e = m - 2;
                    else
                        s = m + 1;
                } else if (a[m] == a[m + 1]) {
                    if ((m + 1 - s + 1) & 1)
                        e = m - 1;
                    else
                        s = m + 2;
                } else
                    return a[m];
            }
        }
        return 0;
    }
};