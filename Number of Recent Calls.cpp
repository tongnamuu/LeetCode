class RecentCounter {
   public:
    queue<int> q;
    RecentCounter() {}
    int ping(int t) {
        q.push(t);
        int s = max(0, t - 3000);
        while (!q.empty() && q.front() < s) {
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
