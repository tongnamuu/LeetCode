class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int, vector<int>> x;
        map<int, vector<int>> y;
        int max_x = -1;
        int min_x = 1000000000;
        for(vector<int>& b : buildings) {
            x[b[0]].push_back(b[1]);
            y[b[1]].push_back(b[0]);
            max_x = max(max_x, b[0]);
            min_x = min(min_x, b[0]);
        }
        int ans = 0;
        for(auto i = x.begin();i!=x.end();i++) {
            int a = i -> first;
            if (a == max_x || a == min_x) continue;
            vector<int>& k = i -> second;
            sort(k.begin(), k.end());
            int m = k.size();
            for(int j=1;j<m-1;j++) {
                int v= k[j];
                vector<int>& temp = y[v];
                sort(temp.begin(), temp.end());
                if (temp[0] < a && temp.back() > a) ans++;
            }
        }
        return ans;
    }
};
