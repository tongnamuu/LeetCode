class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int i = 0; int j = 0;
        int ans = 0;
        while(i<n+k && j < n+k) {
            if(j-i+1 == k) {
                if(i<n || j< n) ans++;
                int nextj = (j+1) % n;
                if(colors[nextj] != colors[j%n]) {
                    j++;
                } else {
                    i++;
                    if(j<i) j = i;
                }
            } else if(j-i+1 > k) {
                i++;
                if(j<i) j = i;
            } else {
                int nextj = (j+1) % n;
                if(colors[nextj] != colors[j%n]) {
                    j++;
                } else {
                    i++;
                    if(j<i) j=i;
                }
            }
        }   
       
        return ans;
    }
    
};