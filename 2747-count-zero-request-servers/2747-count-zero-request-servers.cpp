class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {

        sort(
            logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        vector<pair<int, int>> q;
        for (int i = 0; i < queries.size(); i++)
            q.push_back({queries[i], i});
        sort(q.begin(), q.end());
        unordered_map<int, int> freq;
        int active = 0;
        int l = 0, r = 0;
        vector<int> ans(queries.size());
        for (auto& [t, idx] : q) {
            while (r < logs.size() && logs[r][1] <= t) {
                int server = logs[r][0];
                if (freq[server] == 0)
                    active++;
                freq[server]++;
                r++;
            }
            while (l < r && logs[l][1] < t - x) {
                int server = logs[l][0];
                freq[server]--;
                if (freq[server] == 0)
                    active--;
                l++;
            }
            ans[idx] = n - active;
        }
        return ans;
    }
};