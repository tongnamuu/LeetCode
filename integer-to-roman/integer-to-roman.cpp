class Solution {
public:
    char ones[5]={'#','I','X','C','M'};
    char fives[4]={'#','V','L','D'};
    string getString(int num, int pos){
        switch(num){
        case 1:
            return string(1,ones[pos]);
            
        case 2:
            return string(2,ones[pos]);
            
        case 3:
            return string(3,ones[pos]);
        case 4:
            return string(1,ones[pos]) + string(1,fives[pos]);
        case 5:
            return string(1,fives[pos]);
        case 6:
            return string(1,fives[pos])+string(1,ones[pos]);
        case 7:
            return string(1,fives[pos])+string(2,ones[pos]);
        case 8:
            return string(1,fives[pos])+string(3,ones[pos]);
        case 9:
            return string(1,ones[pos]) + string(1,ones[pos+1]);
        default:
            return "";
        }
    }
    string intToRoman(int num) {
        string ans;
        int pos = 1;
        while(num){
            ans = getString(num%10, pos)+ans;
            pos++;
            num/=10;
        }
        return ans;
    }
};