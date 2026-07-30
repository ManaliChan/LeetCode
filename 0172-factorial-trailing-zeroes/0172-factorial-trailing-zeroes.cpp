class Solution {
public:
    int trailingZeroes(int n) {
        if(n == 0){
            return 0;
        }
        int zeroes = 0;

        while(n != 0){
            int d = n / 5;
            zeroes += d;

            n /= 5;
        }
    return zeroes;
    }
};