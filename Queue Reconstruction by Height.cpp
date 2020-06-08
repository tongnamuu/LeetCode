class Solution {
   public:
    void find(vector<vector<int>>& a, vector<bool>& check, vector<vector<int>>& ans) {
        int choose = -1;
        for (int i = 0; i < a.size(); ++i) {
            if (check[i]) continue;
            int h = a[i][0];
            int ord = a[i][1];
            int cnt = 0;
            for (int j = 0; j < ans.size(); ++j) {
                if (h <= ans[j][0]) ++cnt;
            }
            if (cnt == ord) {
                if (choose == -1 || a[choose][0] > h) {
                    choose = i;
                }
            }
        }
        check[choose] = true;
        ans.push_back(a[choose]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (people.empty()) return people;
        sort(people.begin(), people.end(), [](const auto& u, const auto& v) {
            if (u[0] == v[0]) return u[1] < v[1];
            return u[0] > v[0];
        });
        for (int i = 0; i < people.size(); ++i) {
            vector<int> temp = people[i];
            if (people[i][1] != i) {
                people.erase(people.begin() + i);
                people.insert(people.begin() + temp[1], temp);
            }
        }
        return people;
    }
};