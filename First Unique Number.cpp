class FirstUnique {
   public:
    queue<int> q;
    unordered_map<int, int> check;
    FirstUnique(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (check.find(nums[i]) == check.end()) {
                q.push(nums[i]);
                check[nums[i]] = 1;
            } else {
                check[nums[i]]++;
            }
        }
    }

    int showFirstUnique() {
        while (!q.empty()) {
            int x = q.front();
            if (check[x] == 1) {
                return x;
            }
            q.pop();
        }
        return -1;
    }

    void add(int value) {
        if (!check[value]) {
            q.push(value);
            check[value] = 1;
        } else {
            check[value]++;
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */