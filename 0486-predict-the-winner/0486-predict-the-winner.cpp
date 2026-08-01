class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1) >= 0;
    }
    int helper(vector<int>& nums, int i, int j) {
        if (i == j) return nums[i]; 
        int pickLeft  = nums[i] - helper(nums, i + 1, j);
        int pickRight = nums[j] - helper(nums, i, j - 1);

        return max(pickLeft, pickRight);
    }
};