class Solution {
public:
    string to_str(int v) {
        if(v==0) return "0";
        string temp;
        while(v) {
            temp += (v%10) + '0';
            v/=10;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int i=0;i<(1<<10);i++) {
            int cnt = 0;
            for(int j=0;j<10;j++) {
                if(i&(1<<j)) {
                    cnt++;
                }
            }
            if(cnt != turnedOn) continue;
            int hour = 0;
            int minute = 0;
            for(int j=0;j<4;j++) {
                if(i&(1<<j)) {
                    hour += (1<<j);
                }
            }
            for(int j=4;j<10;j++) {
                if(i&(1<<j)) {
                    minute += (1<<(j-4));
                }
            }
            if(hour>11||hour<0) continue;
            if(minute>59||minute<0) continue;
            string temp = to_str(hour) + ":";
            if(minute<10) temp += "0";
            temp += to_str(minute);
            ans.push_back(temp);
        }
        return ans;
    }
};