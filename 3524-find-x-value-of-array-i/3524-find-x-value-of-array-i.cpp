class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k), st(k);
        for (int value : nums) {
            int rem = value % k;
            vector<long long> next(k);
            for (int r = 0; r < k; r++) {
                int p = (r * rem) % k;
                next[p] += st[r];
                res[p] += st[r];
            }
            next[rem]++;
            res[rem]++;
            st = next;
        }
        return res;
    }
};