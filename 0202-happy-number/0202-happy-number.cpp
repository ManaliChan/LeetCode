class Solution {
public:
    bool isHappy(int n) {

        int sum = 0;
        unordered_set<int> seen;

        while(n != 1){
            if(seen.count(n) > 0){
                return false;
            }

            seen.insert(n);

            int sum = 0;

            while(n > 0){
                int digit = n % 10;
                sum = sum + digit*digit;
                n = n/10;
            }

            n = sum;
        }
       return true; 
    }
};