class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> zeros;
        int i = 0;
        for (char c : s)
            if (c == '0') ++i;
            else if (i) zeros.push_back(exchange(i, 0));
        if (i) zeros.push_back(i);
        int maxzeros = 0;
        for (int i = 1; i < zeros.size(); ++i)
            maxzeros = max(maxzeros, zeros[i-1] + zeros[i]);

        return ranges::count(s, '1') + maxzeros;
    }
};