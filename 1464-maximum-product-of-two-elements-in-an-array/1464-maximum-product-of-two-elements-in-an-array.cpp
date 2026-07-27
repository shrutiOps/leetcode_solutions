class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = INT_MIN;
        for (int i =0; i< nums.size(); i++){
            for(int j=i+1; j< nums.size() ; j++){
                int prod= (nums[i]-1)*(nums[j]-1);
                maxprod = max(maxprod , prod);
            }
        }
        return maxprod;
    }
};