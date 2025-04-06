class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n =nums.size();
        if(!n || n == 1) return nums;
        sort(nums.begin(),nums.end());
        vector<int>d(n);
        vector<int>from(n, -1);
        for(int i=0;i<n;++i){
            d[i]=1;
            for(int j=0;j<i;++j){
                if(nums[i]%nums[j]==0){
                    if(d[i]<d[j]+1){
                        d[i]=d[j]+1;
                        from[i]=j;
                    }
                
                }
            }
        }

        int ans = 0;
        int ans_idx=-1;
        for(int i=0;i<n;++i){
            if(ans<d[i]){
                ans=d[i];
                ans_idx=i;
            }
        }
        int idx=ans_idx;
        vector<int>answer;
        answer.push_back(nums[idx]);
        while(from[idx]!=-1){
            idx=from[idx];
            answer.push_back(nums[idx]);
        }
        return answer;
    }
};