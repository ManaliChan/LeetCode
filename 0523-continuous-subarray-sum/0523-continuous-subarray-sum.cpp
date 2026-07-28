class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        if (n < 2)
            return false;

       
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }

    
        for (int i = 0; i < n; i++) {
            nums[i] %= k;
        }

        unordered_map<int, int> mp;
        mp[0] = -1;

        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i]) != mp.end()) {
                if (i - mp[nums[i]] > 1)
                    return true;
            } else {
                mp[nums[i]] = i;
            }
        }

        return false;
    }
};