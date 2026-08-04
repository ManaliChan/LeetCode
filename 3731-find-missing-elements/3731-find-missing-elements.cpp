class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n =nums.size();

        unordered_set<int> st(nums.begin(), nums.end());

        int maxEl = *max_element(begin(nums), end(nums));
        int minEl = *min_element(begin(nums), end(nums));

        vector<int> result;

        for(int i=minEl; i<maxEl; i++){
            if(!st.count(i)){
                result.push_back(i);
            }
        }

        return result;
    }
};