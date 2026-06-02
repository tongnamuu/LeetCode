class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = 2147483647;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int start1 = landStartTime[i];
                int end1 = landStartTime[i] + landDuration[i];
                int start2 = waterStartTime[j];
                int end2 = waterStartTime[j] + waterDuration[j];
                if(start1 < start2) {
                    ans = min(ans, end1 + max(0, start2 - end1) + waterDuration[j]);
                } else {
                    ans = min(ans, end2 + max(0, start1 - end2) + landDuration[i]);
                }
            }
        }
        return ans;
    }
};