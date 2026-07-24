class Solution {
public:
    bool isPowerOfThree(int n) {
        
        long long power = pow(3,19);
        if(n>0 && power%n==0){
            return true;
        }

        return false;

    }
};