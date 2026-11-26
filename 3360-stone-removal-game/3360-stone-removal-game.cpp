class Solution {
public:
    bool canAliceWin(int n) {
        bool win = false;
        int count = 10;
        while(true) {
            if(count>n) {
                return win;
            } else {
                n -= count;
                win ^= 1;
            }
            count--;
        }
    }
};