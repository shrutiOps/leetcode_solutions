class Solution {
public:
    string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    vector<pair<char, int>> vec(freq.begin(), freq.end());
    sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
        if (a.second == b.second) return a.first < b.first; 
        return a.second > b.second;
    });
    string result;
    for (auto &p : vec) {
        result.append(p.second, p.first); 
    }

    return result;
}
};