class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
      int start = 0;
      int end = 10000000;
      while(start<=end) {
        int mid = (start + end) / 2;
        if(ok(mid, candies, k)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
      }
      return end;

    }
    bool ok(int target, vector<int>& a, long long people) {
        if(target == 0) return true;
        for(int i : a) {
            people -= i/target;
        }
        return people <= 0L;
    }
};