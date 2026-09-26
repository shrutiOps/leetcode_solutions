class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> dict;
        for (auto &kv : knowledge) {
            dict[kv[0]] = kv[1];
        }
        string result;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                int j = i+1;
                while (j < n && s[j] != ')') j++;
                string key = s.substr(i+1, j-i-1);
                if (dict.count(key)) result += dict[key];
                else result += "?";
                i = j; 
            } else {
                result += s[i];
            }
        }
        return result;
    }
};
