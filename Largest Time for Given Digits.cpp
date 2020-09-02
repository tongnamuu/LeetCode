class Solution {
   public:
    string make_time(int a, int b) {
        string temp;
        if (a < 10) {
            temp += '0';
        }
        temp += to_string(a);
        temp += ':';
        if (b < 10) {
            temp += '0';
        }
        temp += to_string(b);
        return temp;
    }
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(), A.end());
        int max_hour = -1, max_min = -1;
        do {
            int hour = 10 * A[0] + A[1];
            int minute = 10 * A[2] + A[3];
            if (hour >= 0 and hour <= 23 and minute >= 0 and minute <= 59) {
                if (hour > max_hour) {
                    max_hour = hour;
                    max_min = minute;
                } else if (hour == max_hour) {
                    if (minute > max_min) {
                        max_min = minute;
                    }
                }
            }
        } while (next_permutation(A.begin(), A.end()));
        if (max_hour == -1)
            return "";
        return make_time(max_hour, max_min);
    }
};
