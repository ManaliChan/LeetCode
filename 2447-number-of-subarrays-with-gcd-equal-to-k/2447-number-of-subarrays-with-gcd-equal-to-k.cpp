class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int res = 0;
        for(int i = 0, n = nums.size(); i < n; ++i){
            int curr = nums[i];
            for(int j = i; j < n && nums[j] % k == 0; ++j){
                curr = __gcd(curr , nums[j]);
                if(curr == k) ++res;
            }
        }
        return res;
    }
};