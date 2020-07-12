class Solution {
   public:
    long long toNum(const string& s) {
        long long num = 0;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            num *= 10;
            num += s[i] - '0';
        }
        return num;
    }
    vector<long long> stack_to_vector(stack<long long>& s) {
        vector<long long> nums;
        while (!s.empty()) {
            nums.push_back(s.top());
            s.pop();
        }
        reverse(nums.begin(), nums.end());
        return nums;
    }
    pair<vector<long long>, vector<char>> mul(const vector<long long>& nums, const vector<char>& op) {
        stack<long long> s;
        s.push(nums[0]);
        vector<char> new_op;
        for (int i = 0; i < op.size(); ++i) {
            if (op[i] == '*') {
                long long num = s.top();
                s.pop();
                s.push(num * nums[i + 1]);
            } else if (op[i] == '/') {
                long long num = s.top();
                s.pop();
                s.push(num / nums[i + 1]);
            } else {
                s.push(nums[i + 1]);
                new_op.push_back(op[i]);
            }
        }
        vector<long long> new_nums = stack_to_vector(s);
        return {new_nums, new_op};
    }
    pair<vector<long long>, vector<char>> add(const vector<long long>& nums, const vector<char>& op) {
        stack<long long> s;
        s.push(nums[0]);
        vector<char> new_op;
        for (int i = 0; i < op.size(); ++i) {
            if (op[i] == '+') {
                long long num = s.top();
                s.pop();
                s.push(num + nums[i + 1]);
            } else if (op[i] == '-') {
                long long num = s.top();
                s.pop();
                s.push(num - nums[i + 1]);
            } else {
                s.push(nums[i + 1]);
                new_op.push_back(op[i]);
            }
        }
        vector<long long> new_nums = stack_to_vector(s);
        return {new_nums, new_op};
    }
    int calculate(string s) {
        int len = s.size();
        vector<long long> num;
        vector<char> op;
        string temp;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '*' || s[i] == '+' || s[i] == '-' || s[i] == '/') {
                op.push_back(s[i]);
                num.push_back(toNum(temp));
                temp = "";
            } else if (s[i] >= '0' && s[i] <= '9')
                temp += s[i];
        }
        num.push_back(toNum(temp));
        auto p = mul(num, op);
        p = add(p.first, p.second);
        return p.first[0];
    }
};