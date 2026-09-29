class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2 != 0) return false;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(m+n, -1)));
        return dfs(0, 0, 0, grid, dp);
    }

    bool dfs(int i, int j, int balance, vector<vector<char>>& grid,
             vector<vector<vector<int>>>& dp) {
        int m = grid.size(), n = grid[0].size();
        if (i >= m || j >= n) return false;
        if (grid[i][j] == '(') balance++;
        else balance--;
        if (balance < 0) return false;
        if (i == m-1 && j == n-1) return balance == 0;
        if (dp[i][j][balance] != -1) return dp[i][j][balance];

        bool res = dfs(i+1, j, balance, grid, dp) || dfs(i, j+1, balance, grid, dp);
        return dp[i][j][balance] = res;
    }
};
