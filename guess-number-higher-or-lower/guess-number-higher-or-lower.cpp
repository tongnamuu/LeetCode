/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int s = 1, e = n;
        while(s<=e) {
            int m = s + (e-s)/2;
            int r = guess(m);
            if(!r) return m;
            if(r==-1) e = m - 1;
            else s = m + 1;
        }
        return 0;
    }
};