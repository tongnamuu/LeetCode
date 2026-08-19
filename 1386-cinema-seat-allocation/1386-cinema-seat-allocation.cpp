class Solution {
public:
    int deadCount(int* temp) {
        if(temp[1]==1) {
            if(temp[0]==1 && temp[2]==1) {
                return 0;
            }
            return 1;
        } else {
            if(temp[0]==1 && temp[2]==1) {
                return 0;
            } else if(temp[0]==1 && temp[2]==0) {
                return 1;
            } else if(temp[0]==0 && temp[2]==1) {
                return 1;
            }
            return 2;
        }
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end(), [](const vector<int>& u, const vector<int>& v) {
            if(u[0]==v[0]) {
                return u[1] < v[1];
            }
            return u[0] < v[0];
        });
        int ans = n*2;
        int cur = reservedSeats[0][0];
        int i = 0;
        int x = reservedSeats.size();
        int temp[3] = {1,1,1};
        while(i<x) {
            if(cur==reservedSeats[i][0]) {
                int reserve = reservedSeats[i][1];
                if(reserve==2||reserve==3) {
                    temp[0] = 0;
                } else if (reserve == 4|| reserve==5) {
                    temp[0] = 0;
                    temp[1] = 0;
                } else if(reserve == 6 || reserve==7) {
                    temp[1] = 0;
                    temp[2] = 0;
                } else if(reserve==8|| reserve == 9) {
                    temp[2] = 0;
                }
                i++;
            } else {
                ans -= deadCount(temp);
                cur = reservedSeats[i][0];
                temp[0] = 1;
                temp[1] = 1;
                temp[2] = 1;
            }
        }
        ans -= deadCount(temp);
        return ans;
    }
};