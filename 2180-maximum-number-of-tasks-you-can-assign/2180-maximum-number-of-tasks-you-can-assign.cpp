class Solution {
public:
    struct D {
        int val;
        int used;
        bool operator<(const D& a) const {
            return this -> val > a.val;
        }
    };
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int n = tasks.size();
        int m = workers.size();
        int s = 0;
        int e = min(n,m);
        //5 5 8 9 9
        //1 2 4 6 6
        while(s<=e) {
            int m = (s+e) / 2;
            if(good(m, tasks, workers, pills, strength)) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return e;
    }
    bool good(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int p = pills;
        deque<int> ws;
        int m =workers.size();
        int ptr = workers.size() - 1;

        for (int i = mid - 1; i >= 0; --i) {
            while (ptr >= m - mid && workers[ptr] + strength >= tasks[i]) {
                ws.push_front(workers[ptr]);
                --ptr;
            }
            if (ws.empty()) {
                return false;
            } else if (ws.back() >= tasks[i]) {
                    ws.pop_back();
            } else {
                if (!p) {
                    return false;
                }
                --p;
                ws.pop_front();
            }
        }
            return true;
    }
};