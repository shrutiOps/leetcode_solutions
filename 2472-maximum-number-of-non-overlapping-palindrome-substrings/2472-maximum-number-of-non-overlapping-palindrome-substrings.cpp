class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // Precompute palindrome table
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (len == 1) isPal[i][j] = true;
                else if (len == 2) isPal[i][j] = (s[i] == s[j]);
                else isPal[i][j] = (s[i] == s[j]) && isPal[i+1][j-1];
            }
        }

        int count = 0;
        int i = 0;
        while (i + k - 1 < n) {
            bool found = false;
            for (int len = k; len <= k+1 && i+len-1 < n; len++) {
                if (isPal[i][i+len-1]) {
                    count++;
                    i += len; 
                    found = true;
                    break;
                }
            }
            if (!found) i++;
        }
        return count;
    }
};
