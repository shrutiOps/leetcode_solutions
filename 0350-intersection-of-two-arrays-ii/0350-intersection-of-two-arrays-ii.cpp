class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        vector<int> res;
        for (int n : nums1) {
            freq[n]++;
        }
        for (int n : nums2) {
            if (freq[n] > 0) {
                res.push_back(n);
                freq[n]--;
            }
        }
        
        return res;
    }
};
