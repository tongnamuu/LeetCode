class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> obs;
        for(vector<int>& o : obstacles) {
            obs.insert({o[0],o[1]});
        }
        pair<int,int>pos = {0,0};
        int dir = 0;
        int ans = 0;
        for(int i : commands) {
            if(i==-1) {
                dir = (dir + 1) % 4;
            } else if(i==-2) {
                dir -= 1;
                if (dir==-1) dir = 3;
            } else {
                for(int k=0;k<i;k++) {
                    pos.first += dx[dir];
                    pos.second += dy[dir];
                    if(obs.contains(pos)) {
                        pos.first -= dx[dir];
                        pos.second -= dy[dir];
                        break;
                    }
                }
                //cout<<pos.first<<' '<<pos.second<<'\n';
                ans = max(ans, pos.first*pos.first + pos.second*pos.second);
            }
        }
        return ans;
    }
};