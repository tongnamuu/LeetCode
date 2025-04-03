class Solution {
public:
    int seg[400004];
    int init(int node, int s, int e, vector<int>& a) {
        if(s==e) {
            return seg[node] = a[s];
        }
        int m = (s+e) / 2;
        int x = init(node*2, s, m, a);
        int y = init(node*2+1, m+1, e, a);
        return seg[node] = max(x,y);
    }
    int query(int node, int s, int e, int x, int y) {
        if(e< x || s > y) {
            return -2000000000;
        }
        if(x <= s && y >= e) {
            return seg[node];
        }
        int m = (s+e)/2;
        return max(query(node*2, s, m, x,y) , query(node*2+1, m+1, e, x,y));
    }
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        init(1,0,n-1,nums);
        long long ans = 0;
        for(int i=1;i<n-1;i++) {
            int x = query(1,0,n-1,0,i-1);
            int y = nums[i];
            int z = query(1,0,n-1,i+1, n-1);
            ans = max(ans, (long long)(x-y)*z);
        }
        return ans;
    }
};