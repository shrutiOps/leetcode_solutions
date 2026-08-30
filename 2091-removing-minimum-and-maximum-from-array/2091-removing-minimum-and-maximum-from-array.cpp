class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int left = 0;
        int right = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[left])
                left = i;
            if (nums[i] > nums[right])
                right = i;
        }
        if (left < right)
            swap(left, right);    
        int ans = nums.size();
        for (int i = 0; i <= nums.size(); i++) {
            int res = 0;
            if (right >= i)
                res = nums.size() - right;
            else if (left >= i)
                res = nums.size() - left;
            ans = min(ans, i + res);
        }
        return ans;
    }
};