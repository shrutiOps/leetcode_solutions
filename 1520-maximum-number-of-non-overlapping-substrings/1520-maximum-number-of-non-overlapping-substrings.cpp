class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = max(last[c], i);
        }

        vector<pair<int,int>> intervals;
        for (int c = 0; c < 26; c++) {
            if (last[c] == -1) continue;
            int l = first[c], r = last[c];
            bool valid = true;
            for (int i = l; i <= r; i++) {
                int cc = s[i] - 'a';
                if (first[cc] < l) { valid = false; break; }
                r = max(r, last[cc]);
            }
            if (valid) intervals.push_back({l, r});
        }
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });
        vector<string> res;
        int prevEnd = -1;
        for (auto &it : intervals) {
            if (it.first > prevEnd) {
                res.push_back(s.substr(it.first, it.second - it.first + 1));
                prevEnd = it.second;
            }
        }
        return res;
    }
};
