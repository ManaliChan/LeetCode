class Solution {
public:
    int mod = 1e9 + 7;
    int power(int n, long long p){

             int result = 1;
             while(p > 0){
                if(p%2 == 1){
                    result = (1LL * result * n) % mod;
                }
                    n = (1LL * n * n )% mod;
                    p = p/2;
                
             }
             return result % mod;
    }
    int countGoodNumbers(long long n) {
        
   
            long long even = (n+1)/2;
            long long odd = n/2;

            return (1LL * power(5, even) * power(4, odd)) % mod;

    }
};