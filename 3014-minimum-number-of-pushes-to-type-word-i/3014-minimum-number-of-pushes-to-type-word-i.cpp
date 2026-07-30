class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int totalPushes = 0;
        int index = 0; 
        for (int f : freq){
            if (f == 0) break; 
            int cost = (index / 8) + 1; 
            totalPushes += f * cost;
            index++;
        }
        
        return totalPushes;
    }
};