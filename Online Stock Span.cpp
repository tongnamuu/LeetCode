class StockSpanner {
   public:
    stack<int> s;
    stack<int> w;
    StockSpanner() {
        s = stack<int>();
        w = stack<int>();
    }

    int next(int price) {
        int ans = 1;
        while (!s.empty() && s.top() <= price) {
            s.pop();
            ans += w.top();
            w.pop();
        }
        s.push(price);
        w.push(ans);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */