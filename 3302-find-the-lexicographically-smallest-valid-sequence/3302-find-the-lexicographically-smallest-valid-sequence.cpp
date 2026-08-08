class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> suffix(m, -1);
        int i = n - 1, j = m - 1;
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                suffix[j] = i;
                j--;
            }
            i--;
        }
        vector<int> ans;
        bool changed = false;
        j = 0;
        for (i = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            else if (!changed &&
                     (j == m - 1 || i < suffix[j + 1])) {
                ans.push_back(i);
                changed = true;
                j++;
            }
        }
        if (j == m)
            return ans;
        return {};
    }
};