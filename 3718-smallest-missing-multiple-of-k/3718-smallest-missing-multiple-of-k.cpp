class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector <int> arr(102,0);
        for( auto num : nums){
            if(num % k == 0){
                arr[num / k] = 1;
            }
        }
        for( int i =1; i < arr.size() ; i++){
            if(arr[i] == 0){
                return i * k;
                break;
            }
        }
        return -1;
    }
};