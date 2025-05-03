class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int ans = 2147483647;
        for(int d=1;d<=6;++d){
            bool find = true;
            int cnt = 0;
            for(int i=0;i<A.size();++i){
                if(A[i]!= d){
                    if(B[i] == d){
                        ++cnt;
                    }
                    else{
                        find = false;
                        break;
                    }
                }
            }
            if(!find) continue;
            ans = min(ans, cnt);
            cnt = 0;
            for(int i=0;i<B.size();++i){
                if(B[i] != d){
                    if(A[i] == d){
                        ++cnt;
                    }
                    else{
                        find = false;
                        break;
                    }
                }
            }
            ans = min(ans, cnt);
        }
        if(ans!=2147483647) return ans;
        return -1;
    }
};
