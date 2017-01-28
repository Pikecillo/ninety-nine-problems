// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int lo = 0, hi = n, num, cmp;
        
        do {
            num = lo + ((hi - lo) >> 1);
            cmp = guess(num);
            
            if(cmp == -1)
                hi = num;
            if(cmp == 1)
                lo = num + 1;
            
        } while(cmp != 0);
        
        return num;
    }
};
