class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp = arr;
        vector<int>x(arr.size());
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        for(int i=0;i<arr.size();i++) {
            x[i] = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin() + 1;
        }
        return x;
    }
};