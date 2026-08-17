class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n+1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + stoneValue[i];
        }
        
        vector<vector<int>> memo(n, vector<int>(n, -1));
        
        function<int(int,int)> dp = [&](int l, int r) {
            if (l == r) return 0;
            if (memo[l][r] != -1) return memo[l][r];
            
            int best = 0;
            for (int i = l; i < r; i++) {
                int left = prefix[i+1] - prefix[l];
                int right = prefix[r+1] - prefix[i+1];
                
                if (left < right) {
                    best = max(best, left + dp(l, i));
                } else if (right < left) {
                    best = max(best, right + dp(i+1, r));
                } else {
                    best = max(best, left + max(dp(l, i), dp(i+1, r)));
                }
            }
            return memo[l][r] = best;
        };
        
        return dp(0, n-1);
    }
};
