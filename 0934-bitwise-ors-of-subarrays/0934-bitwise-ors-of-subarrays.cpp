class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> result;
        set<int>temp;

        for(int i: arr) {
            set<int> next;
            next.insert(i);
            for(int j : temp) {
                next.insert(i|j);
            }
            result.insert(next.begin(), next.end());
            temp = next;
            
        }
        return result.size();
    }
};