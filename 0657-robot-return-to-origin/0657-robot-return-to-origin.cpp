class Solution {
public:
    bool judgeCircle(string moves) {
        int v = 0;
        int h = 0;
        for(char c : moves) {
            if(c=='U') {
                v++;
            } else if(c=='D') {
                v--;
            } else if(c=='L') {
                h--;
            } else if(c=='R') {
                h++;
            }
        }
        return v == 0 && h == 0;
    }
};