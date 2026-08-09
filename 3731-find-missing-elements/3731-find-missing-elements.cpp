class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        vector<bool> present(mx - mn + 1, false);
        for (int x : nums)
            present[x - mn] = true;
        vector<int> ans;
        for (int i = mn; i <= mx; i++) {
            if (!present[i - mn])
                ans.push_back(i);
        }
        return ans;
    }
};