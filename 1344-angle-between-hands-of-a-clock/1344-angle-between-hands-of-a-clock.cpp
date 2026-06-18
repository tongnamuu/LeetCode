class Solution {
public:
    double abs(int x) {
        return x >=0 ? x : -x;
    }
    double angleClock(int hour, int minutes) {
        int x = 2*hour*30 + minutes;
        int y = 6*minutes*2;
        double ans = abs(x-y) / 2;
        if (ans >= 180) ans = 360 - ans;
        return ans;
    }
};