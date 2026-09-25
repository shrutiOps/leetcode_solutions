class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        set<string> res = parse(expression);
        return vector<string>(res.begin(), res.end());
    }

private:
    set<string> parse(string expr) {
        vector<set<string>> parts;
        int n = expr.size(), i = 0;
        while (i < n) {
            if (expr[i] == '{') {
                int j = i, bal = 0;
                do {
                    if (expr[j] == '{') bal++;
                    if (expr[j] == '}') bal--;
                    j++;
                } while (bal > 0);
                set<string> sub = unionSplit(expr.substr(i+1, j-i-2));
                parts.push_back(sub);
                i = j;
            } else if (isalpha(expr[i])) {
                parts.push_back({string(1, expr[i])});
                i++;
            } else {
                i++; 
            }
        }
        set<string> res = {""};
        for (auto &p : parts) {
            set<string> newRes;
            for (auto &prefix : res) {
                for (auto &suffix : p) {
                    newRes.insert(prefix + suffix);
                }
            }
            res.swap(newRes);
        }
        return res;
    }
    set<string> unionSplit(string expr) {
        set<string> res;
        int bal = 0, start = 0;
        for (int i = 0; i <= expr.size(); i++) {
            if (i == expr.size() || (expr[i] == ',' && bal == 0)) {
                set<string> sub = parse(expr.substr(start, i - start));
                res.insert(sub.begin(), sub.end());
                start = i + 1;
            } else if (expr[i] == '{') bal++;
            else if (expr[i] == '}') bal--;
        }
        return res;
    }
};
