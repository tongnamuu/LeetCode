class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=1) return n;
        sort(points.begin(), points.end(), [](const auto& a, const auto& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int cnt = 1;
        int ans = 0;
        int start = points[0][0];
        int end = points[0][1];
        for(int i=1;i<n;++i){
            int s = points[i][0];
            int e = points[i][1];
            if(end < s){ // 새로 시작하는 경우
                ans += cnt;
                cnt = 1;
                start = s;
                end = e;
            }
            else{
                if(e < end){
                    ans += cnt;
                    cnt = 0;
                    start = s;
                    end = e;
                }
            }
        }
        ans += cnt;
        return ans;
    }
};
